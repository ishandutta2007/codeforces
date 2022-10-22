#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MIN(a,b) ((a)<(b)?(a):(b))

const i32 mod = 1000000007;

i32 calc (i64 n) {
  if (n == 0) return 0;
  i64 sum = 0;
  i64 head[2] = {1, 2};
  i32 bit = 0;
  for (i64 len = 1; n > 0; n -= len, len *= 2, bit ^= 1) {
    i64 d = MIN(n, len) % mod;
    sum = (sum + head[bit] * d % mod + (d - 1 + mod) % mod * d % mod) % mod;
    head[bit] = (head[bit] + 2 * len) % mod;
  }
  return sum;
}

void run (void) {
  i64 l = read_int();
  i64 r = read_int();
  i32 ans = (calc (r) - calc (l - 1) + mod) % mod;
  print_int (ans);
  puts("");
}

int main (void) {
  run ();
  return 0;
}