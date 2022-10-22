#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 n = read_int();
  i32 *a = ALLOC (n, i32);
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  i64 p = 0;
  i64 q = 0;
  i64 max = 0;
  for (i32 x = 0, y = n - 1;;) {
    if (p == q) {
      max = p;
    }
    if (x > y) break;
    if (p <= q) {
      p += a[x++];
    } else {
      q += a[y--];
    }
  }
  print_int (max);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}