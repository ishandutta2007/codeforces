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

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))
#define SORT(a,n,cmp) msort((a),(n),sizeof(*(a)),cmp)

void run (void) {
  i32 n = read_int();
  i32 *a = ALLOC (n, i32);
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  i32 *b = ALLOC (n, i32);
  i32 sum = a[0];
  i32 p = a[0];
  i32 m = 0;
  b[m++] = 0;
  for (i32 i = 1; i < n; ++i) {
    sum += a[i];
    if (2 * a[i] <= a[0]) {
      p += a[i];
      b[m++] = i;
    }
  }
  if (2 * p <= sum) {
    puts ("0");
  } else {
    print_int (m);
    puts ("");
    for (i32 i = 0; i < m; ++i) {
      print_int (b[i] + 1);
      putchar (i == m - 1 ? '\n' : ' ');
    }
  }
}

int main (void) {
  run ();
  return 0;
}