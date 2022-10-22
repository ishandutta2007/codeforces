#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define POS(i, j) ((i) * m + (j))

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i32 h = read_int();
  i32 *a = (i32 *) calloc (m + n + n * m, sizeof (i32));
  i32 *b = a + m;
  i32 *c = b + n;
  for (i32 i = 0; i < m + n + m * n; ++i) {
    a[i] = read_int();
  }
  i32 *ans = (i32 *) calloc (n * m, sizeof (i32));
  while (h--) {
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < m; ++j) {
        if (b[i] > 0 && a[j] > 0 && c[POS(i, j)]) {
          ans[POS(i, j)]++;
        }
      }
    }
    for (i32 i = 0; i < n + m; ++i) {
      a[i]--;
    }
  }
  for (i32 i = 0; i < n; ++i) {
    for (i32 j = 0; j < m; ++j) {
      print_int (ans[POS(i, j)]);
      putchar (j == m - 1 ? '\n' : ' ');
    }
  }
}

int main (void) {
  run ();
  return 0;
}