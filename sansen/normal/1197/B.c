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
  i32 *a = ALLOC (n + 2, i32);
  for (i32 i = 1; i <= n; ++i) {
    a[i] = read_int();
  }
  a[0] = a[n + 1] = -2;
  i32 l = 1;
  while (a[l] < n) ++l;
  i32 r = l;
  for (i32 i = n - 1; i >= 1; --i) {
    if (a[l - 1] == i) {
      l--;
    } else if (a[r + 1] == i) {
      r++;
    } else {
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