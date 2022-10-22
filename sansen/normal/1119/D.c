#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

int cmp (const void *a, const void *b) {
  i64 d = *(i64 *)a - *(i64 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

i32 search (i64 v, const i64 *d, const i32 n) {
  i32 l = 0;
  i32 r = n;
  while (r - l > 1) {
    i32 m = (l + r) / 2;
    if (d[m] <= v) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

void run (void) {
  i32 n = read_int();
  i64 *s = (i64 *) calloc (n, sizeof (i64));
  for (i32 i = 0; i < n; ++i) {
    s[i] = read_int();
  }
  qsort (s, n, sizeof (i64), cmp);
  i32 len = 1;
  for (i32 i = 1; i < n; ++i) {
    if (s[i] == s[len - 1]) continue;
    s[len++] = s[i];
  }
  n = len;
  i64 *d = (i64 *) calloc (n, sizeof (i64));
  d[0] = 1000000000000000000LL + 100;
  for (i32 i = 1; i < n; ++i) {
    d[i] = s[i] - s[i - 1] - 1;
  }
  qsort (d, n, sizeof (i64), cmp);
  i64 *sum = (i64 *) calloc (n + 1, sizeof (i64));
  for (i32 i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + d[i - 1];
  }
  i32 q = read_int();
  while (q--) {
    i64 l = read_int();
    i64 r = read_int();
    i64 m = r - l;
    i64 ans = n;
    if (m <= d[0]) {
      ans += n * m;
    } else {
      i32 k = search (m, d, n);
      ans += sum[k + 1] + (n - 1 - k) * m;
    }
    print_int (ans);
    putchar (q == 0 ? '\n' : ' ');
  }
}

int main (void) {
  run ();
  return 0;
}