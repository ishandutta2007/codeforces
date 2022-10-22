#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

const i32 mod = 1000000007;

i32 inv (i32 a) {
  i32 t = 1;
  while (a > 1) {
    t = (i64) t * (mod - mod / a) % mod;
    a = mod % a;
  }
  return t;
}

i32 mod_pow (i32 r, i32 n) {
  i32 t = 1;
  i32 s = r;
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod;
    s = (i64) s * s % mod;
    n >>= 1;
  }
  return t;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void matmul (i32 *c, i32 *a, i32 *b, i32 n) {
  static i32 *tmp = NULL;
  if (tmp == NULL) {
    tmp = (i32 *) calloc (n * n, sizeof (i32));
  }
  memset (tmp, 0, sizeof (i32) * n * n);
  for (i32 i = 0; i < n; ++i) {
    for (i32 k = 0; k < n; ++k) {
      for (i32 j = 0; j < n; ++j) {
	tmp[i * n + j] = (tmp[i * n + j] + (i64) a[i * n + k] * b[k * n + j]) % mod;
      }
    }
  }
  memcpy (c, tmp, sizeof (i32) * n * n);
}

void run (void) {
  i32 n = read_int();
  i32 k = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  i32 cnt[2] = {0, 0};
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
    cnt[a[i]]++;
  }
  if (cnt[0] == 0 || cnt[1] == 0) {
    puts("1");
    return;
  }
  i32 d = 0;
  for (i32 i = 0; i < cnt[0]; ++i) {
    d += a[i];
  }
  const i32 m = MIN(cnt[0], cnt[1]) + 1;
  i32 *t = (i32 *) calloc (m * m, sizeof (i32));
  i32 *s = (i32 *) calloc (m * m, sizeof (i32));
  for (i32 i = 0; i < m; ++i) {
    t[i * m + i] = 1;
    s[i * m + i] = cnt[0] * (cnt[0] - 1) / 2 + cnt[1] * (cnt[1] - 1) / 2 + (cnt[0] - i) * i + i * (cnt[1] - i);
    if (i + 1 < m) {
      s[i * m + i + 1] = (cnt[0] - i) * (cnt[1] - i);
    }
    if (i - 1 >= 0) {
      s[i * m + i - 1] = i * i;
    }
  }
  i32 p = inv (n * (n - 1) / 2);
  for (i32 i = 0; i < m * m; ++i) {
    s[i] = (i64) s[i] * p % mod;
  }
  while (k > 0) {
    if (k & 1) matmul (t, t, s, m);
    matmul (s, s, s, m);
    k >>= 1;
  }
  i32 ans = t[d * m + 0];
  print_int (ans);
  puts("");
}

int main (void) {
  run ();
  return 0;
}