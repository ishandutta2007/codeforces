#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  i32 q = read_int();
  while (q--) {
    i64 n = read_int();
    i32 cnt[3] = {0, 0, 0};
    i32 d[3] = {2, 3, 5};
    for (i32 i = 0; i < 3; ++i) {
      while (n % d[i] == 0) {
        cnt[i]++;
        n /= d[i];
      }
    }
    i32 ans = n > 1 ? -1 : cnt[0] + 2 * cnt[1] + 3 * cnt[2];
    print_int (ans);
    puts ("");
  }
}

int main (void) {
  run ();
  return 0;
}