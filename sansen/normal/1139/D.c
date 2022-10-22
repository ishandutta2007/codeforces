#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

const i32 mod = 1000000007;

i32 inv (i32 a) {
  i32 t = 1;
  while (a > 1) {
    t = (i64) t * (mod - mod / a) % mod;
    a = mod % a;
  }
  return t;
}

void run (void) {
  const i32 n = read_int();
  i32 *factor = (i32 *) calloc (n + 1, sizeof (i32));
  for (i32 i = 1; i <= n; ++i) {
    factor[i] = i;
  }
  for (i32 i = 2; i * i <= n; ++i) {
    if (factor[i] < i) continue;
    for (i32 j = i * i; j <= n; j += i) {
      factor[j] = i;
    }
  }
  i32 *dp = (i32 *) calloc (n + 1, sizeof (i32));
  dp[1] = 0;
  for (i32 i = 2; i <= n; ++i) {
    i32 f[64];
    f[0] = 1;
    i32 len = 1;
    i32 t = i;
    while (t > 1) {
      i32 p = factor[t];
      while (t % p == 0) {
	t /= p;
      }
      for (i32 j = 0; j < len; ++j) {
	f[j + len] = f[j] * p;
      }
      len *= 2;
    }
    if (f[len - 1] != i) {
      dp[i] = dp[f[len - 1]];
      continue;
    }
    i32 prob[64];
    for (i32 j = 0; j < len; ++j) {
      prob[j] = (i64) (n / f[j]) * inv(n) % mod;
    }
    for (i32 j = len - 1; j >= 0; --j) {
      for (i32 k = j - 1; k >= 0; --k) {
	if ((j & k) == k) {
	  prob[k] = (prob[k] - prob[j] + mod) % mod;
	}
      }
    }
    i32 local = 1;
    for (i32 j = 0; j < len - 1; ++j) {
      local = (local + (i64) prob[j] * dp[f[j]]) % mod;
    }
    dp[i] = (i64) local * inv((1 - prob[len - 1] + mod) % mod) % mod;
  }
  i32 ans = 1;
  for (i32 i = 1; i <= n; ++i) {
    ans = (ans + (i64)dp[i] * inv(n)) % mod;
  }
  print_int(ans);
  puts("");
}

int main (void) {
  run ();
  return 0;
}