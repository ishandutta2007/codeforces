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

void run (void) {
  char *s = ALLOC (1000000 + 1, char);
  scanf ("%s", s);
  i32 n = strlen (s);
  char *x = ALLOC (n + 1, char);
  char *y = ALLOC (n + 1, char);
  i32 l = 0;
  i32 r = n - 1;
  i32 p = 0;
  i32 q = 0;
  while (r - l >= 3) {
    if (s[l] == s[r]) {
    } else if (s[l + 1] == s[r]) {
      l++;
    } else if (s[l] == s[r - 1]) {
      r--;
    } else {
      l++;
      r--;
    }
    x[p++] = s[l++];
    y[q++] = s[r--];
  }
  if (l < r && s[l] == s[r]) {
    x[p++] = s[l];
    y[q++] = s[r];
  } else if (l <= r) {
    x[p++] = s[l];
  }
  for (i32 i = 0; i < p; ++i) {
    putchar (x[i]);
  }
  for (i32 i = q - 1; i >= 0; --i) {
    putchar (y[i]);
  }
  puts ("");
}

int main (void) {
  run ();
  return 0;
}