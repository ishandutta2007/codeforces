#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

i32* func (i32 n) {
  i32 *a = ALLOC (n + 1, i32);
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  for (i32 i = n - 1; i >= 0; --i) {
    a[i] += a[i + 1];
  }
  i32 *p = ALLOC (n + 1, i32);
  for (i32 i = 1; i <= n; ++i) {
    p[i] = 2001 * i;
  }
  for (i32 i = 0; i < n; ++i) {
    for (i32 j = i + 1; j <= n; ++j) {
      i32 v = a[i] - a[j];
      p[j - i] = MIN (p[j - i], v);
    }
  }
  free (a);
  return p;
}

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i32 *a = func (n);
  i32 *b = func (m);
  i64 x = read_int();
  i32 max = 0;
  for (i32 i = 1; i <= n; ++i) {
    for (i32 j = 1; j <= m; ++j) {
      i64 y = (i64) a[i] * b[j];
      if (y <= x) {
        max = MAX (max, i * j);
      }
    }
  }
  print_int (max);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}