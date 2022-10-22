#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

i32 digit (i32 n) {
  i32 d = 0;
  while (n > 0) {
    n /= 10;
    d++;
  }
  return d;
}

#define POS(d,k) ((d) * (m + 1) + (k))

void run (void) {
  i32 n = read_int();
  const i32 m = 10;
  i32 *a = ALLOC ((m + 1) * (m + 1), i32);
  i32 *cnt = ALLOC (m + 1, i32);
  for (i32 i = 0; i < n; ++i) {
    i32 v = read_int();
    i32 d = digit (v);
    cnt[d]++;
    for (i32 j = 0; v > 0; ++j, v /= 10) {
      a[POS(d, j)] += v % 10;
    }
  }
  const i32 mod = 998244353;
  i64 ans = 0;
  for (i32 i = 1; i <= m; ++i) {
    if (cnt[i] == 0) continue;
    for (i32 j = 1; j <= m; ++j) {
      if (cnt[j] == 0) continue;
      i64 v = 0;
      i64 d = 1;
      for (i32 x = i, y = j; x > 0 || y > 0;x--, y--) {
        if (y > 0) {
          v += (i64) a[POS(j, j - y)] * d % mod * cnt[i] % mod;
          d = 10 * d % mod;
        }
        if (x > 0) {
          v += (i64) a[POS(i, i - x)] * d % mod * cnt[j] % mod;
          d = 10 * d % mod;
        }
      }
      ans += v;
    }
  }
  ans %= mod;
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}