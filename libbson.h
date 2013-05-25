/**
 * libbson headers 
 */

#ifndef __LIBBSON_H
#define __LIBBSON_H

#define BSON_DOUBLE             0x01
#define BSON_STRING             0x02
#define BSON_DOCUMENT           0x03
#define BSON_ARRAY              0x04
#define BSON_BINARY             0x05
#define BSON_UNDEFINED          0x06
#define BSON_OBJECT_ID          0x07
#define BSON_BOOLEAN            0x08
#define BSON_DATETIME           0x09
#define BSON_NULL               0x0A
#define BSON_REGEXP             0x0B
#define BSON_DB_POINTER         0x0C
#define BSON_JAVASCRIPT         0x0D
#define BSON_SYMBOL             0x0E
#define BSON_JAVASCRIPT_SCOPE   0x0F
#define BSON_INT32              0x10
#define BSON_TIMESTAMP          0x11
#define BSON_INT64              0x12
#define BSON_MINIMUM            0xFF
#define BSON_MAXIMUM            0x7F

extern void bson_register_handler( int type, void *func );
extern void bson_decode( char *buf );

/* typedefs for bson things. compound elements like 
   documents and arrays, and valueless elements like
   null, undef, and min/max, don't have types. */
typedef union { 
  double value;
  char _bytes[8];
} bson_double_t;

typedef union { 
  int value;
  char _bytes[4];
} bson_int32_t;

typedef union { 
  int value;
  char _bytes[8];
} bson_int64_t;

typedef struct {
  bson_int32_t length;
  char *value;
} bson_string_t;

typedef struct { 
  bson_int32_t length;
  char subtype;
  char *data;
} bson_binary_t;

typedef struct { 
  char value[12];
} bson_object_id_t;

typedef struct { 
  char value;
} bson_bool_t;

typedef union { 
  long int value;
  char _bytes[8];
} bson_datetime_t;

typedef struct { 
  char *pattern;
  char *flags;
} bson_regexp_t;

typedef struct {     
  bson_int32_t length;
  char *namespace;
  bson_object_id_t *object_id;
} bson_db_pointer_t;

typedef struct {
  int length;
  char *value;
} bson_js_t;

typedef struct { 
  int length;
  char *value;
} bson_symbol_t;

typedef struct { 
  int length;
  char *code;
} bson_js_w_s_t;

typedef int bson_timestamp_t;


/* for deserialization support */
typedef union { 
  double dbl;
  char bytes[8];
} _dbl_tmp;

#endif
