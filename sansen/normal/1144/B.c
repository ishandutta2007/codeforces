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

#define ABS(a) ((a) < 0 ? -(a) : (a))

int cmp (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 n = read_int();
  i32 *a = (i32 *) calloc (2 * n, sizeof (i32));
  i32 len[2] = {0, 0};
  for (i32 i = 0; i < n; ++i) {
    i32 v = read_int();
    i32 k = v & 1;
    a[k * n + len[k]++] = v;
  }
  qsort (a, len[0], sizeof (i32), cmp);
  qsort (a + n, len[1], sizeof (i32), cmp);
  if (ABS(len[0] - len[1]) <= 1) {
    puts("0");
    return;
  }
  i32 b = len[0] < len[1] ? 1 : 0;
  i32 sum = 0;
  for (i32 i = 0; i + len[b ^ 1] < len[b] - 1; ++i) {
    sum += a[b * n + i];
  }
  print_int (sum);
  puts("");
}

int main (void) {
  run ();
  return 0;
}