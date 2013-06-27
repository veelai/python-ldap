/* common utility macros
 * See http://www.python-ldap.org/ for details.
 * $Id: common.h,v 1.8 2009/04/17 12:19:09 stroeder Exp $ */

#ifndef __h_common 
#define __h_common 

#define PY_SSIZE_T_CLEAN

#include "Python.h"

#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif

#if defined(MS_WINDOWS)
#include <winsock.h>
#else /* unix */
#include <netdb.h>
#include <sys/time.h>
#include <sys/types.h>
#endif

/* Backwards compability with Python prior 2.5 */
#if PY_VERSION_HEX < 0x02050000
typedef int Py_ssize_t;
#define PY_SSIZE_T_MAX INT_MAX
#define PY_SSIZE_T_MIN INT_MIN
#endif

#include <string.h>
#define streq( a, b ) \
	( (*(a)==*(b)) && 0==strcmp(a,b) )

void LDAPadd_methods( PyObject*d, PyMethodDef*methods );
#define PyNone_Check(o) ((o) == Py_None)

//backports to Python2.5
#if PY_MAJOR_VERSION < 3
#ifndef PyBytes_FromStringAndSize
#define PyBytes_FromStringAndSize PyString_FromStringAndSize
#endif
#ifndef PyBytes_FromString
#define PyBytes_FromString PyString_FromString
#endif
#ifndef PyBytes_AsString
#define PyBytes_AsString PyString_AsString
#endif
#ifndef PyBytes_Size
#define PyBytes_Size PyString_Size
#endif
#ifndef PyBytes_Check
#define PyBytes_Check PyString_Check
#endif
#endif /* PY_MAJOR_VERSION */

#endif /* __h_common_ */

