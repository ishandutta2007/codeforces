#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

i64 gcd (i64 a, i64 b) {
  i64 r = a % b;
  while (r > 0) {
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i64 *x = (i64 *) calloc (n, sizeof (i64));
  for (i32 i = 0; i < n; ++i) {
    x[i] = read_int();
  }
  i64 g  = x[1] - x[0];
  for (i32 i = 1; i + 1 < n; ++i) {
    g = gcd (g, x[i + 1] - x[i]);
  }
  for (i32 i = 0; i < m; ++i) {
    i64 p = read_int();
    if (g % p == 0) {
      puts ("YES");
      print_int (x[0]);
      putchar (' ');
      print_int (i + 1);
      puts ("");
      return;
    }
  }
  puts ("NO");
}

int main (void) {
  run ();
  return 0;
}