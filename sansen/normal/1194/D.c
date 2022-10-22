#include<stdio.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void run (void) {
  i32 t = read_int();
  while (t--) {
    i64 n = read_int();
    i64 k = read_int();
    if (k % 3 == 0) {
      i32 r = n % (k + 1);
      puts (r == k || r % 3 != 0 ? "Alice" : "Bob");
    } else {
      puts (n % 3 == 0 ? "Bob" : "Alice");
    }
  }
}

int main (void) {
  run();
  return 0;
}