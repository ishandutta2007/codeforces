#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

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
  i32 a = read_int();
  i32 b = read_int();
  if (a == b) {
    puts ("0");
    return;
  }
  if (a > b) {
    i32 s = b;
    b = a;
    a = s;
  }
  i64 min = (i64)a / gcd (a, b) * b;
  i32 min_k = 0;
  i32 d = b - a;
  for (i32 i = 1; i * i <= d; ++i) {
    if (d % i != 0) continue;
    i32 f = i;
    if (a % f != 0) {
      i32 k = f - a % f;
      i64 v = (i64) (a + k) / gcd (a + k, b + k) * (b + k);
      if (v < min || (v == min && k < min_k)) {
	min = v;
	min_k = k;
      }
    }
    f = d / i;
    if (a % f != 0) {
      i32 k = f - a % f;
      i64 v = (i64) (a + k) / gcd (a + k, b + k) * (b + k);
      if (v < min || (v == min && k < min_k)) {
	min = v;
	min_k = k;
      }
    }
  }
  print_int (min_k);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}