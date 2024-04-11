#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

int can (i64 m, i64 *a, i32 *b, i32 n, i32 *dp, i32 k) {
  memset (dp, 0, sizeof (i32) * (k + 1));
  k--;
  i32 r = k;
  for (i32 i = 0; i < n; ++i) {
    i64 t = a[i];
    while (t / b[i] + 1 <= k && r >= 0) {
      dp[t / b[i] + 1]++;
      t += m;
      r--;
    }
    if (r < 0) return 0;
  }
  for (i32 i = 1; i <= k; ++i) {
    dp[i] += dp[i - 1];
    if (dp[i] > i) return 0;
  }
  return 1;
}

void run (void) {
  i32 n = read_int();
  i32 k = read_int();
  i64 *a = (i64 *) calloc (n, sizeof (i64));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  i32 *b = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    b[i] = read_int();
  }
  i32 *dp = (i32 *) calloc (k + 1, sizeof (i32));
  i64 l = -1;
  i64 r = (i64) k * 10000000;
  if (!can (r, a, b, n, dp, k)) {
    puts("-1");
    return;
  }
  while (r - l > 1) {
    i64 m = (l + r) / 2;
    if (can (m, a, b, n, dp, k)) {
      r = m;
    } else {
      l = m;
    }
  }
  print_int (r);
  puts("");
}

int main (void) {
  run ();
  return 0;
}