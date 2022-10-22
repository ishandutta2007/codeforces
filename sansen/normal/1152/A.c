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
  i32 m = read_int();
  i32 cnt[2] = {0, 0};
  while (n--) {
    i32 a = read_int()&1;
    cnt[a]++;
  }
  i32 ans = 0;
  while (m--) {
    i32 b = read_int()&1;
    if (cnt[b ^ 1] > 0) ans++;
    cnt[b ^ 1]--;
  }
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}