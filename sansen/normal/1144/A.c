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
  while (n--) {
    char s[101];
    scanf ("%s", s);
    i32 cnt[26] = {0};
    for (i32 i = 0; s[i] != '\0'; ++i) {
      cnt[s[i] - 'a']++;
    }
    i32 l,r;
    for (l = 0; cnt[l] == 0; ++l);
    for (r = 26 - 1; cnt[r] == 0; --r);
    int ok = 1;
    for (i32 j = l; j <= r; ++j) {
      if (cnt[j] != 1) {
	ok = 0;
      }
    }
    puts (ok ? "Yes" : "No");
  }
}

int main (void) {
  run ();
  return 0;
}