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
  i32 *l = (i32 *) calloc (n, sizeof (i32));
  i32 *r = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    l[i] = read_int();
    r[i] = read_int();
  }
  i32 *ans = (i32 *) calloc (m, sizeof (i32));
  i32 len = 0;
  for (i32 i = 1; i <= m; ++i) {
    i32 ok = 1;
    for (i32 j = 0; j < n; ++j) {
      if (l[j] <= i && i <= r[j]) {
	ok = 0;
      }
    }
    if (ok) ans[len++] = i;
  }
  print_int (len);
  puts("");
  for (i32 i = 0; i < len; ++i) {
    print_int (ans[i]);
    if (i < len - 1) putchar (' ');
  }
  puts("");
}

int main (void) {
  run ();
  return 0;
}