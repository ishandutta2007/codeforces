#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define POS(i, j) ((i) * c + (j))

int can (i32 *a, i32 r, i32 c, i32 *ans) {
  i32 xor = 0;
  for (i32 i = 0; i < r; ++i) {
    xor ^= a[POS(i, 0)];
  }
  if (xor > 0) return 1;
  for (i32 i = 0; i < r; ++i) {
    i32 h = a[POS(i, 0)];
    for (i32 j = 1; j < c; ++j) {
      if (h != a[POS(i, j)]) {
	ans[i] = j;
	return 1;
      }
    }
  }
  return 0;
}

void run (void) {
  i32 r = read_int();
  i32 c = read_int();
  i32 *a = (i32 *) calloc (r * c, sizeof (i32));
  for (i32 i = 0; i < r * c; ++i) {
    a[i] = read_int();
  }
  i32 *ans = (i32 *) calloc (r, sizeof (i32));
  if (can (a, r, c, ans)) {
    puts("TAK");
    for (i32 i = 0; i < r; ++i) {
      print_int (ans[i] + 1);
      putchar (i == r - 1 ? '\n' : ' ');
    }
  } else {
    puts("NIE");
  }
}

int main (void) {
  run ();
  return 0;
}