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

void run (void) {
  const i32 n = read_int();
  const i32 m = read_int();
  const i64 k = read_int();
  i64 *a = ALLOC (n + 1, i64);
  for (i32 i = 1; i <= n; ++i) {
    a[i] = read_int() + a[i - 1];
  }
  i64 *min = ALLOC (m, i64);
  for (i32 i = 1; i < m; ++i) {
    min[i] = 1000000000000000000LL;
  }
  i64 ans = 0;
  for (i32 i = 1; i <= n; ++i) {
    i64 x = i / m;
    i64 y = i % m;
    for (i32 w = 0; w < i && w < m; ++w) {
      i64 v = a[i] - x * k - min[w] - k * (y - w > 0 ? 1 : 0);
      ans = MAX (ans, v);
    }
    min[y] = MIN (min[y], a[i] - x * k);
  }
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}