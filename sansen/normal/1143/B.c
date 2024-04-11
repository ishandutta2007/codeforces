#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))

i32 calc (i32 n) {
  i32 res = 1;
  while (n > 0) {
    res *= n % 10;
    n /= 10;
  }
  return res;
}

void run (void) {
  const i32 n = read_int();
  const i32 m = 100000;
  i32 max = 0;
  i32 i;
  for (i = 0; i + m <= n; i += m) {
    i32 v = calc(i / m) * 9 * 9 * 9 * 9 * 9;
    max = MAX(max, v);
  }
  for (; i <= n; ++i) {
    i32 v = calc (i);
    max = MAX(max, v);
  }
  print_int (max);
  puts("");
}

int main (void) {
  run ();
  return 0;
}