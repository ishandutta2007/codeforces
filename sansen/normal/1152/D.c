#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  i32 n = read_int();
  i32 *dp = (i32 *) calloc (n + 3, sizeof (i32)) + 1;
  const i32 mod = 1000000000 + 7;
  dp[0] = 1;
  i32 ans = 0;
  for (i32 i = 1; i <= n; ++i) {
    if ((i & 1) == 0) {
      for (i32 j = i - 1; j >= 0; j -= 2) {
	ans = (ans + dp[j]) % mod;
      }
    }
    for (i32 j = i; j >= 0; j -= 2) {
      i32 v = (dp[j - 1] + dp[j + 1]) % mod;
      dp[j] = v;
    }
  }
  for (i32 i = n - 1; i >= 0; --i) {
    if ((i & 1) == 0) {
      for (i32 j = i + 1; j >= 0; j -= 2) {
	ans = (ans + dp[j]) % mod;
      }
    }
    for (i32 j = i; j >= 0; j -= 2) {
      i32 v = (dp[j - 1] + dp[j + 1]) % mod;
      dp[j] = v;
    }
  }
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}