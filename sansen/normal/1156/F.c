#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

const i32 mod = 998244353;

i32 mod_pow (i32 r, i32 n) {
  i32 t = 1;
  i32 s = r;
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod;
    s = (i64) s * s % mod;
    n >>= 1;
  }
  return t;
}

i32 inv (i32 a) {
  return mod_pow (a, mod - 2);
}

i32 *fact = NULL;
i32 *iFact = NULL;
void init_fact (const i32 n) {
  fact = (i32 *) calloc (n + 1, sizeof (i32));
  fact[0] = 1;
  for (i32 i = 1; i <= n; ++i) {
    fact[i] = (i64) i * fact[i - 1] % mod;
  }
  iFact = (i32 *) calloc (n + 1, sizeof (i32));
  iFact[n] = inv (fact[n]);
  for (i32 i = n - 1; i >= 0; --i) {
    iFact[i] = (i64) (i + 1) * iFact[i + 1] % mod;
  }
}

void run (void) {
  i32 n = read_int();
  i32 *cnt = (i32 *) calloc (n + 1, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    cnt[read_int()]++;
  }
  init_fact (n);
  i32 ans = 0;
  i32 *dp = (i32 *) calloc (n + 1, sizeof (i32));
  dp[0] = 1;
  i32 max = 0;
  for (i32 i = 1; i <= n; ++i) {
    if (cnt[i] == 0) continue;
    if (cnt[i] >= 2) {
      i32 way = cnt[i] * (cnt[i] - 1);
      for (i32 j = 0; j <= max; ++j) {
        ans = (ans + (i64) dp[j] * way % mod * fact[n - j - 2]) % mod;
      }
    }
    for (i32 j = max + 1; j > 0; --j) {
      dp[j] = (dp[j] + (i64) cnt[i] * dp[j - 1]) % mod;
    }
    max++;
  }
  ans = (i64) ans * iFact[n] % mod;
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}