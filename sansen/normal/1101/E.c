#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  i32 n = read_int();
  i32 h = 0;
  i32 w = 0;
  while (n--) {
    char s[10];
    scanf ("%s", s);
    i32 x = read_int();
    i32 y = read_int();
    if (x > y) {
      i32 swap = x;
      x = y;
      y = swap;
    }
    if (s[0] == '+') {
      h = h < x ? x : h;
      w = w < y ? y : w;
    } else {
      puts(h <= x && w <= y ? "YES" : "NO");
    }
  }
}

int main (void) {
  run ();
  return 0;
}