#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 n = read_int();
  i32 *a = ALLOC (2 * n, i32);
  i32 *b = a + n;
  for (i32 i = 0; i < 2 * n; ++i) {
    a[i] = read_int();
  }
  i64 *dpA = ALLOC (n + 1, i64);
  i64 *dpB = ALLOC (n + 1, i64);
  dpA[n - 1] = a[n - 1];
  dpB[n - 1] = b[n - 1];
  i64 max = 0;
  for (i32 i = n - 2; i >= 0; --i) {
    dpA[i] = MAX (max, dpB[i + 1]) + a[i];
    dpB[i] = MAX (max, dpA[i + 1]) + b[i];
    max = MAX (max, MAX (dpA[i + 1], dpB[i + 1]));
  }
  i64 ans = MAX (MAX (dpA[0], dpB[0]), MAX (dpA[1], dpB[1]));
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}