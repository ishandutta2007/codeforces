#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void msort_memcpy (uint8_t * restrict dst, uint8_t * restrict src, size_t size) {
  while (size--) {
    *dst++ = *src++;
  }
}

void msort (void * const array, const size_t num, const size_t size, int (* const cmp) (const void *, const void *)) {
  typedef struct operation {
    size_t l;
    size_t r;
    int32_t type;
  } op;
  uint8_t * const a = (uint8_t *) array;
  uint8_t * const tmp = (uint8_t *) malloc (size * num);
  op stack[64];
  int32_t top = 0;
  stack[top++] = (op) {0, num, 0};
  while (top > 0) {
    const op t = stack[--top];
    if (t.l + 1 >= t.r) continue;
    const size_t m = (t.l + t.r) / 2;
    if (t.type == 0) {
      stack[top++] = (op) {t.l, t.r, 1};
      stack[top++] = (op) {t.l, m  , 0};
      stack[top++] = (op) {m  , t.r, 0};
      continue;
    }
    msort_memcpy (tmp, a + t.l * size, (m - t.l) * size);
    size_t i = 0;
    size_t j = m * size;
    size_t k = t.l * size;
    while (i < (m - t.l) * size && j < t.r * size) {
      if (cmp (tmp + i, a + j) <= 0) {
        msort_memcpy (a + k, tmp + i, size);
        i += size;
      } else {
        msort_memcpy (a + k, a + j, size);
        j += size;
      }
      k += size;
    }
    msort_memcpy (a + k, tmp + i, (m - t.l) * size - i);
  }
  free (tmp);
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

int cmp (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

i32 to_index (i32 *z, i32 len, i32 v) {
  i32 l = 0;
  i32 r = len;
  while (r - l > 1) {
    i32 m = (l + r) / 2;
    if (z[m] <= v) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

void calc (const i32 *a, i32 n, i32 m, i32 *row, i32 *dp) {
  i32 *b = (i32 *) calloc (m, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    memcpy (b, a + i * m, sizeof (i32) * m);
    msort (b, m, sizeof (i32), cmp);
    i32 len = 1;
    for (i32 j = 1; j < m; ++j) {
      if (b[j] == b[len - 1]) continue;
      b[len++] = b[j];
    }
    row[i] = len;
    for (i32 j = 0; j < m; ++j) {
      dp[i * m + j] = to_index (b, len, a[i * m + j]);
    }
  }
  free (b);
}

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i32 *a = (i32 *) calloc (n * m, sizeof (i32));
  for (i32 i = 0; i < n * m; ++i) {
    a[i] = read_int();
  }
  i32 *row = (i32 *) calloc (n, sizeof (i32));
  i32 *row_dp = (i32 *) calloc (n * m, sizeof (i32));
  calc (a, n, m, row, row_dp);
  i32 *ta = (i32 *) calloc (n * m, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    for (i32 j = 0; j < m; ++j) {
      ta[j * n + i] = a[i * m + j];
    }
  }
  i32 *col = (i32 *) calloc (m, sizeof (i32));
  i32 *col_dp = (i32 *) calloc (n * m, sizeof (i32));
  calc (ta, m, n, col, col_dp);
  for (i32 i = 0; i < n; ++i) {
    for (i32 j = 0; j < m; ++j) {
      i32 v = MAX(row_dp[i * m + j], col_dp[j * n + i]);
      i32 u = MAX(row[i] - row_dp[i * m + j], col[j] - col_dp[j * n + i]);
      print_int (v + u);
      putchar (j == m - 1 ? '\n' : ' ');
    }
  }
}
int main (void) {
  run ();
  return 0;
}