#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void run (void) {
  i32 q = read_int();
  char *s = ALLOC (4 * 100000 + 1, char);
  i32 *cntX = ALLOC (5 * 10000, i32);
  i32 *cntY = ALLOC (5 * 10000, i32);
  while (q--) {
    const i32 n = read_int();
    const i32 m = read_int();
    for (i32 i = 0; i < n; ++i) {
      scanf ("%s", s + i * m);
    }
    memset (cntX, 0, sizeof (i32) * n);
    memset (cntY, 0, sizeof (i32) * m);
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < m; ++j) {
        if (s[i * m + j] == '*') {
          cntX[i]++;
          cntY[j]++;
        }
      }
    }
    i32 max = 0;;
    for (i32 i = 0; i < n; ++i) {
      for (i32 j = 0; j < m; ++j) {
        i32 b = cntX[i] + cntY[j] - (s[i * m + j] == '*' ? 1 : 0);
        max = MAX (max, b);
      }
    }
    print_int (n + m - 1 - max);
    puts ("");
  }
}

int main (void) {
  run ();
  return 0;
}