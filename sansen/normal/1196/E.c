#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<math.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))
#define SORT(a,n,cmp) msort((a),(n),sizeof(*(a)),cmp)

void print (i32 x, i32 y) {
  print_int (x);
  putchar (' ');
  print_int (y);
  puts ("");
}

void run (void) {
  i32 q = read_int();
  while (q--) {
    i32 b = read_int();
    i32 w = read_int();
    if (!(3 * b + 1 >= w && b <= 3 * w + 1)) {
      puts ("NO");
      continue;
    }
    puts ("YES");
    i32 m = 500000;
    print (m, m);
    print (m, m + 1);
    w--;
    b--;
    i32 p = m + 2;
    while (w > 0 && b > 0) {
      print (m, p);
      print (m, p + 1);
      p += 2;
      w--;
      b--;
    }
    if (b > 0) {
      print (m, m - 1);
      b--;
      for (i32 i = m; i < p && b > 0; i += 2) {
        print (m - 1, i);
        b--;
      }
      for (i32 i = m; i < p && b > 0; i += 2) {
        print (m + 1, i);
        b--;
      }
    } else if (w > 0) {
      print (m, p);
      w--;
      for (i32 i = m + 1; i < p && w > 0; i += 2) {
        print (m - 1, i);
        w--;
      }
      for (i32 i = m + 1; i < p && w > 0; i += 2) {
        print (m + 1, i);
        w--;
      }
    }
  }
}

int main (void) {
  run ();
  return 0;
}