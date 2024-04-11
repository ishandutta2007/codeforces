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
  i32 cnt[3] = {0, 0, 0};
  for (i32 i = 0;i < n; ++i) {
    i32 a = read_int();
    cnt[a]++;
  }
  i32 *ans = (i32 *) calloc (n, sizeof (i32));
  i32 len = 0;
  if (cnt[1] > 0 && cnt[2] > 0) {
    ans[len++] = 2;
    ans[len++] = 1;
    cnt[1]--;
    cnt[2]--;
  }
  while (cnt[2]--) {
    ans[len++] = 2;
  }
  while (cnt[1]--) {
    ans[len++] = 1;
  }
  for (i32 i = 0; i < n; ++i) {
    print_int (ans[i]);
    putchar (i == n - 1 ? '\n' : ' ');
  }
}

int main (void) {
  run ();
  return 0;
}