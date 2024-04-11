#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

int can (i64 *cnt) {
  if (cnt[2] > 0) {
    if (cnt[0] == 0 || cnt[3] == 0) return 0;
  }
  return cnt[0] == cnt[3];
}

void run (void) {
  i64 cnt[4];
  for (i32 i = 0; i < 4; ++i) {
    cnt[i] = read_int();
  }
  puts (can (cnt) ? "1" : "0");
}

int main (void) {
  run ();
  return 0;
}