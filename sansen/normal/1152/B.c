#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

int cond (i32 x) {
  while (x > 0) {
    if ((x & 1) == 0) return 0;
    x >>= 1;
  }
  return 1;
}

void run (void) {
  i32 x = read_int();
  if (cond (x)) {
    puts("0");
    return;
  }
  i32 op[20];
  i32 len = 0;
  while ((x & -x) != x) {
    i32 k = 0;
    while ((x & (1 << k)) == 0) ++k;
    op[len++] = k;
    x ^= (1 << k) - 1;
    x++;
  }
  i32 k = 0;
  while ((1 << k) < x) ++k;
  op[len++] = k;
  print_int (2 * len - 1);
  puts ("");
  for (i32 i = 0; i < len; ++i) {
    print_int (op[i]);
    putchar (i == len - 1 ? '\n' : ' ');
  }
}

int main (void) {
  run ();
  return 0;
}