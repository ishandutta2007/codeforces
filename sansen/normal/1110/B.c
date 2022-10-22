#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

int cmp (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 n = read_int();
  i32 m = read_int();
  i32 k = read_int();
  i32 *b = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    b[i] = read_int();
  }
  i32 *d = (i32 *) calloc (n - 1, sizeof (i32));
  for (i32 i = 0; i < n - 1; ++i) {
    d[i] = b[i + 1] - b[i] - 1;
  }
  qsort (d, n - 1, sizeof (i32), cmp);
  i32 ans = n;
  for (i32 i = 0; i < n - k; ++i) {
    ans += d[i];
  }
  print_int (ans);
  puts("");
}

int main (void) {
  run ();
  return 0;
}