#include<stdio.h>
#include<stdint.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

void run (void) {
  i64 a = read_int();
  i64 b = read_int();
  i64 c = read_int();
  i64 d = read_int();
  i64 x = MIN (MIN (a, b), c);
  i64 z = MAX (MAX (a, b), c);
  i64 y = a + b + c - x - z;
  i64 ans = MAX (0, d - (y - x)) + MAX (0, d- (z - y));
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}