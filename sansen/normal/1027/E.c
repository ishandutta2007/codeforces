#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

#define POS(i, j, k) ((((i) & 1) * (n + 1) + (j)) * (n + 1) + (k))

void run (void) {
  const i32 n = read_int();
  const i32 m = read_int();
  const i32 mod = 998244353;
  i64 *dp = ALLOC (2 * (n + 1) * (n + 1), i64);
  dp[POS(1, 1, 1)] = 1;
  for (i32 i = 1; i < n; ++i) {
    memset (dp + POS(i + 1, 0, 0), 0, sizeof (*dp) * (n + 1) * (n + 1));
    for (i32 j = 1; j <= i; ++j) {
      for (i32 k = 1; k <= i; ++k) {
        dp[POS(i, j, k)] %= mod;
        dp[POS(i + 1, MAX (j, k + 1), k + 1)] += dp[POS(i, j, k)];
        dp[POS(i + 1, j, 1)] += dp[POS(i, j, k)];
      }
    }
  }
  i64 *way = ALLOC (n + 1, i64);
  for (i32 j = 1; j <= n; ++j) {
    for (i32 k = 1; k <= j; ++k) {
      way[j] += dp[POS(n, j, k)] % mod;
    }
  }
  for (i32 i = 1; i <= n; ++i) {
    way[i] %= mod;
  }
  i64 ans = 0;
  for (i32 i = 1; i <= n; ++i) {
    for (i32 j = 1; j <= n; ++j) {
      if (i * j < m) {
        ans += way[i] * way[j] % mod;
      }
    }
  }
  ans = 2 * ans % mod;
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}