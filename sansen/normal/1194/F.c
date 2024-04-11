#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

const i32 mod = 1000000007;

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

i32 *FACT = NULL;
i32 *I_FACT = NULL;
i32 FACT_SIZE = -1;
void init_fact (const i32 n) {
  if (FACT != NULL) {
    free (FACT);
    free (I_FACT);
  }
  FACT_SIZE = n;
  FACT = (i32 *) calloc (n + 1, sizeof (i32));
  FACT[0] = 1;
  for (i32 i = 1; i <= n; ++i) {
    FACT[i] = (i64) i * FACT[i - 1] % mod;
  }
  I_FACT = (i32 *) calloc (n + 1, sizeof (i32));
  I_FACT[n] = inv (FACT[n]);
  for (i32 i = n - 1; i >= 0; --i) {
    I_FACT[i] = (i64) (i + 1) * I_FACT[i + 1] % mod;
  }
}

i32 comb (i32 n, i32 k) {
  if (!(0 <= k && k <= n)) return 0;
  return (i64) FACT[n] * I_FACT[k] % mod * I_FACT[n - k] % mod;
}

void run (void) {
  i32 n = read_int();
  i64 t = read_int();
  init_fact (n);
  i64 ans = 0;
  i64 sum = 0;
  i64 remain = 1;
  i64 right = 1;
  i32 k = 0;
  for (i32 i = 1; i <= n; ++i) {
    sum += read_int();
    ++k;
    right = inv (2) * right % mod;
    while (k >= 0 && sum + k > t) {
      remain = (remain + mod - right) % mod;
      k--;
      right = (i64) comb (i, k) * mod_pow (inv (2), i) % mod;
    }
    if (k < 0) break;
    ans += remain;
  }
  ans %= mod;
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}