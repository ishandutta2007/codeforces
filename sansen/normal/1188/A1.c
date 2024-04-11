#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 n = read_int();
  i32 *d = ALLOC (n, i32);
  for (i32 i = 0; i < 2 * (n - 1); ++i) {
    d[read_int() - 1]++;
  }
  for (i32 i = 0; i < n; ++i) {
    if (d[i] == 2) {
      puts ("NO");
      return;
    }
  }
  puts ("YES");
}

int main (void) {
  run ();
  return 0;
}