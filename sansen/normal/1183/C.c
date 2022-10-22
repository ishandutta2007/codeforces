#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

void run (void) {
  i32 q = read_int();
  while (q--) {
    i64 k = read_int();
    i64 n = read_int();
    i64 a = read_int();
    i64 b = read_int();
    if (n * b >= k) {
      puts ("-1");
    } else {
      i64 x = k - n * b - 1;
      i64 ans = MIN (n, x / (a - b));
      print_int (ans);
      puts ("");
    }
  }
}

int main (void) {
  run ();
  return 0;
}