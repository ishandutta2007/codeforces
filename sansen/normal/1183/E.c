#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MIN(a,b) ((a)<(b)?(a):(b))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

#define POS(i, j) ((i) * (n + 1) + (j))

void run (void) {
  i32 n = read_int();
  i64 k = read_int();
  char *s = ALLOC (n + 1, char);
  scanf ("%s", s);
  i64 *dp = ALLOC ((n + 1) * (n + 1), i64);
  for (i32 i = 0; i <= n; ++i) {
    dp[POS(i, 0)] = 1;
  }
  for (i32 i = 1; i <= n; ++i) {
    for (i32 j = 1; j <= i; ++j) {
      dp[POS(i, j)] = dp[POS(i - 1, j - 1)] + dp[POS(i - 1, j)];
      for (i32 l = i - 1; l > 0; --l) {
        if (s[i - 1] == s[l - 1]) {
          dp[POS(i, j)] -= dp[POS(l - 1, j - 1)];
          break;
        }
      }
    }
  }
  i64 cnt = 0;
  i64 ans = 0;
  for (i32 j = n; j >= 0 && cnt < k; --j) {
    i64 x = MIN (k - cnt, dp[POS(n, j)]);
    cnt += x;
    ans += (n - j) * x;
  }
  if (cnt < k) {
    puts ("-1");
  } else {
    print_int (ans);
    puts ("");
  }
}

int main (void) {
  run ();
  return 0;
}