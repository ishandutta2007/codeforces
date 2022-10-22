#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 q = read_int();
  i32 *a = ALLOC (200000, i32);
  while (q--) {
    i32 n = read_int();
    i32 k = read_int();
    i32 odd = 0;
    for (i32 i = 0; i < n; ++i) {
      a[i] = read_int() & 1;
      odd += a[i];
    }
    i32 cond = (odd >= k && (odd - k) % 2 == 0);
    puts (cond ? "YES" : "NO");
    if (cond) {
      i32 y = 0;
      while (k > 1) {
        if (a[y] & 1) {
          print_int (y + 1);
          putchar (' ');
          k--;
        }
        y++;
      }
      print_int (n);
      puts ("");
    }
  }
}

int main (void) {
  run ();
  return 0;
}