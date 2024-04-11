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
  const i32 n = read_int();
  const i32 k = read_int();
  const i32 a = read_int();
  const i32 b = read_int();
  const i64 m = (i64) n * k;
  i64 min = (i64) n * k;
  i64 max = 1;
  for (i32 i = 0; i < 4; ++i) {
    const i32 s = i >= 2 ? a : (k - a) % k;
    for (i32 j = 0; j < 4; ++j) {
      i32 t = (j & 1) ? (k - b) % k : b;
      if (t <= s) {
	i64 d = m - (s - t);
	i64 v = m / gcd (d, m);
	min = MIN(min, v);
	max = MAX(max, v);
	t += k;
      }
      for (i64 l = t; l < m; l += k) {
	i64 d = l - s;
	i64 v = m / gcd (d, m);
	min = MIN(min, v);
	max = MAX(max, v);
      }
    }
  }
  print_int (min);
  putchar(' ');
  print_int (max);
  puts("");
}

int main (void) {
  run ();
  return 0;
}