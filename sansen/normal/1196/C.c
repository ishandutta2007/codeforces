#include<stdio.h>
#include<stdint.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

void run (void) {
  i32 q = read_int();
  while (q--) {
    i32 n = read_int();
    i64 max_x = 100000;
    i64 min_x = -100000;
    i64 max_y = 100000;
    i64 min_y = -100000;
    for (i32 i = 0; i < n; ++i) {
      i64 x = read_int();
      i64 y = read_int();
      if (read_int() == 0) {
        min_x = MAX (min_x, x);
      }
      if (read_int() == 0) {
        max_y = MIN (max_y, y);
      }
      if (read_int() == 0) {
        max_x = MIN (max_x, x);
      }
      if (read_int() == 0) {
        min_y = MAX (min_y, y);
      }
    }
    if (min_x <= max_x && min_y <= max_y) {
      print_int (1);
      putchar (' ');
      print_int (min_x);
      putchar(' ');
      print_int (min_y);
      puts ("");
    } else {
      puts ("0");
    }
  }
}

int main (void) {
  run ();
  return 0;
}