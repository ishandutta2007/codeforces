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

const i32 mod = 998244353;

i64 calc (i32 n, i32 k, i32 cond) {
  i64 dp[2]= {0, 1};
  while (n--) {
    i64 x = (k - 1) * dp[1] % mod;
    i64 y = (dp[0] + (k - 2) * dp[1]) % mod;
    dp[0] = x;
    dp[1] = y;
  }
  return dp[cond];
}

void run (void) {
  const i32 n = read_int();
  const i32 k = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  i64 ans = 1;
  for (i32 begin = 0; begin < 2; ++begin) {
    i32 i = begin;
    while (i < n && a[i] == -1) {
      i += 2;
    }
    if (i >= n) {
      ans = ans * k % mod;
      for (i32 i = begin + 2; i < n; i += 2) {
	ans = ans * (k - 1) % mod;
      }
      continue;
    }
    for (i32 j = i - 2; j >= 0; j -= 2) {
      ans = ans * (k - 1) % mod;
    }
    while (i < n) {
      i32 cnt = 0;
      i32 l = i;
      i += 2;
      while (i < n && a[i] == -1) {
	cnt++;
	i+=2;
      }
      if (i >= n) {
	while (cnt > 0) {
	  ans = ans * (k - 1) % mod;
	  cnt--;
	}
      } else {
	ans = ans * calc (cnt, k, a[l] != a[i]) % mod;
      }
    }
  }
  print_int (ans);
  puts("");
}

int main (void) {
  run ();
  return 0;
}