#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

const i32 mod = 1000000 + 3;

#define ADD(x, a) do{(x) += (a); if ((x) >= mod) (x) -= mod;} while (0)
#define SUB(x, a) do{(x) += mod - (a); if ((x) >= mod) (x) -= mod;} while (0)

i32 inv (i32 a) {
  i32 t = 1;
  while (a > 1) {
    t = (i64) t * (mod - mod / a) % mod;
    a = mod % a;
  }
  return t;
}

void gauss (i32 *a, i32 *b, i32 n) {
  for (i32 i = 0; i < n; ++i) {
    i32 p = inv (a[i * n + i]);
    for (i32 j = i; j < n; ++j) {
      a[i * n + j] = (i64) a[i * n + j] * p % mod;
    }
    b[i] = (i64) b[i] * p % mod;
    for (i32 j = i + 1; j < n; ++j) {
      i32 p = a[j * n + i];
      for (i32 k = i; k < n; ++k) {
	SUB(a[j * n + k], (i64)p * a[i * n + k] % mod);
      }
      SUB(b[j], (i64)b[i] * p % mod);
    }
  }
  for (i32 i = n - 1; i >= 0; --i) {
    for (i32 j = i - 1; j >= 0; --j) {
      SUB(b[j], (i64) b[i] * a[j * n + i] % mod);
      a[j * n + i] = 0;
    }
  }
}

i32 query (i32 x) {
  putchar ('?');
  putchar (' ');
  print_int (x);
  putchar ('\n');
  fflush (stdout);
  return read_int();
}

void run (void) {
  const i32 k = 11;
  i32 *m = (i32 *) calloc (k * k, sizeof (i32));
  i32 *b = (i32 *) calloc (k, sizeof (i32));
  for (i32 x = 0; x < k; ++x) {
    b[x] = query (x);
    for (i32 j = 0, p = 1; j < k; ++j, p = (i64) p * x % mod) {
      m[x * k + j] = p;
    }
  }
  gauss (m, b, k);
  for (i32 x = 0; x < mod; ++x) {
    i32 y = 0;
    for (i32 j = k - 1; j >= 0; --j) {
      y = ((i64) y * x + b[j]) % mod;
    }
    if (y == 0) {
      putchar ('!');
      putchar (' ');
      print_int (x);
      puts("");
      return;
    }
  }
  puts ("! -1");
}

int main (void) {
  run ();
  return 0;
}