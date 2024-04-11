#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MIN(a,b) ((a)<(b)?(a):(b))

void run (void) {
  i32 n = read_int();
  i32 k = read_int();
  if (n < (i64) k * (k + 1) / 2) {
    puts ("NO");
    return;
  }
  n -= k * (k + 1) / 2;
  i32 *dp = (i32 *) calloc (k, sizeof (i32));
  dp[0] = n / k;
  n %= k;
  for (i32 i = 1; i < k; ++i) {
    dp[i] = dp[i - 1];
    i32 prev = dp[i - 1] + i;
    i32 now = dp[i] + i + 1;
    i32 v = MIN(2 * prev - now, n / (k - i));
    dp[i] += v;
    n -= v * (k - i);
  }
  if (n > 0) {
    puts ("NO");
    return;
  }
  puts ("YES");
  for (i32 i = 0; i < k; ++i) {
    print_int (dp[i] + i + 1);
    putchar (i == k - 1 ? '\n' : ' ');
  }
}

int main (void) {
  run ();
  return 0;
}