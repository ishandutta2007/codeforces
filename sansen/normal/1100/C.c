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

void run (void) {
  i32 n = read_int();
  i32 r = read_int();
  const double s = cos (2 * 3.141592653589793 / n);
  double ll = 0;
  double rr = 7 * r;
  for (i32 iter = 0; iter < 60; iter++) {
    double m = (ll + rr) / 2;
    double a = r + m;
    double b = 2 * m;
    if ((2 * a * a - b * b) / (2 * a * a) < s) {
      rr = m;
    } else {
      ll = m;
    }
  }
  printf ("%.7f\n", (ll + rr) / 2);
}

int main (void) {
  run ();
  return 0;
}