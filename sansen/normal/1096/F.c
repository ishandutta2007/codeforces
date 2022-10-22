#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

const i32 mod = 998244353;

i32 mod_pow (i32 r, i32 n) {
  i32 t = 1;
  i32 s = r;
  while (n > 0) {
    if (n & 1) t = (i64) t * s % mod;
    s = (i64) s * s % mod;
    n >>= 1;
  }
  return t;
}

i32 inv (i32 a) {
  return mod_pow (a, mod - 2);
}

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

void add (i32 *bit, i32 x, i32 v) {
  i32 n = bit[0];
  for (i32 i = x; i <= n; i += i & -i) {
    bit[i] += v;
  }
}

i32 get_sum (i32 *bit, i32 x) {
  i32 sum = 0;
  for (i32 i = x; i > 0; i -= i & -i) {
    sum += bit[i];
  }
  return sum;
}

void run (void) {
  i32 n = read_int();
  i32 *p = ALLOC (n, i32);
  i32 cnt = 0;
  for (i32 i = 0; i < n; ++i) {
    p[i] = read_int();
    cnt += p[i] == -1 ? 1 : 0;
  }
  i32 *bit = ALLOC (n + 1, i32);
  bit[0] = n;
  i64 ans = 0;
  for (i32 i = n - 1; i >= 0; --i) {
    if (p[i] == -1) continue;
    ans += get_sum (bit, p[i]);
    add (bit, p[i], 1);
  }
  if (cnt > 0) {
    ans += (i64) cnt * (cnt - 1) % mod * inv (4) % mod;
    i32 prob = inv (cnt);
    for (i32 i = 0, l = 0; i < n; ++i) {
      if (p[i] == -1) {
        ++l;
        continue;
      }
      i32 r = cnt - l;
      i32 k = p[i] - get_sum (bit, p[i]);
      ans += (i64) r * k % mod * prob % mod;
      ans += (i64) l * (cnt - k) % mod * prob % mod;
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