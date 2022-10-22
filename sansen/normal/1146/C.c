#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))

void run (void) {
  i32 n = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  i32 *b = (i32 *) calloc (n, sizeof (i32));
  i32 max = 0;
  for (i32 i = 0; i < 8; ++i) {
    i32 x = 0;
    i32 y = 0;
    for (i32 j = 0; j < n; ++j) {
      if ((j >> i) & 1) {
	a[x++] = j;
      } else {
	b[y++] = j;
      }
    }
    if (x > 0 && y > 0) {
      print_int (x);
      putchar (' ');
      print_int (y);
      putchar(' ');
      for (i32 j = 0; j < x; ++j) {
	print_int (a[j] + 1);
	putchar(' ');
      }
      for (i32 j = 0; j < y; ++j) {
	print_int (b[j] + 1);
	putchar(j == y - 1 ? '\n' : ' ');
      }
      fflush (stdout);
      i32 d = read_int();
      max = MAX(max, d);
    }
  }
  print_int (-1);
  putchar(' ');
  print_int (max);
  putchar('\n');
  fflush (stdout);
  free (a);
  free (b);
}

int main (void) {
  i32 t = read_int();
  while (t--) {
    run();
  }
  return 0;
}