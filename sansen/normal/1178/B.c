#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  char *s = ALLOC (1000000 + 1, char);
  scanf ("%s", s);
  i32 n = strlen (s);
  i64 *dp = ALLOC (4, i64);
  dp[0] = 1;
  for (i32 i = 1; i < n; ++i) {
    if (s[i] == 'v' && s[i - 1] == 'v') {
      dp[3] += dp[2];
      dp[1] += dp[0];
    } else if (s[i] == 'o') {
      dp[2] += dp[1];
    }
  }
  print_int (dp[3]);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}