#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

const i32 mod = 998244353;

i32 popcnt (i32 n) {
  i32 k = 0;
  while (n > 0) {
    k += n & 1;
    n >>= 1;
  }
  return k;
}

typedef struct count_val {
  i64 cnt;
  i64 sum;
} node;

i64 calc (i64 n, i32 k) {
  if (n == 0) return 0;
  const i32 p = 10;
  i32 digit[20];
  i32 len = 0;
  while (n > 0) {
    digit[len++] = n % p;
    n /= p;
  }
  node *now = ALLOC (1 << p, node);
  node *next = ALLOC (1 << p, node);
  i32 sup = 0;
  i64 sup_val = 0;
  for (i32 i = len - 1; i >= 0; --i) {
    memset (next, 0, sizeof (node) * (1 << p));
    for (i32 b = 0; b < (1 << p); ++b) {
      for (i32 d = 0; d < p; ++d) {
        next[b | (1 << d)].sum += p * now[b].sum + d * now[b].cnt;
        next[b | (1 << d)].cnt += now[b].cnt;
      }
    }
    for (i32 d = (i == len - 1 ? 1 : 0); d < digit[i]; ++d) {
      next[sup | (1 << d)].sum += sup_val * p + d;
      next[sup | (1 << d)].cnt += 1;
    }
    if (i < len - 1) {
      for (i32 d = 1; d < p; ++d) {
        next[1 << d].sum += d;
        next[1 << d].cnt += 1;
      }
    }
    for (i32 b = 0; b < (1 << p); ++b) {
      now[b].sum = next[b].sum % mod;
      now[b].cnt = next[b].cnt % mod;
    }
    sup |= 1 << digit[i];
    sup_val = (p * sup_val + digit[i]) % mod;
  }
  i64 ans = popcnt (sup) <= k ? sup_val % mod : 0;
  for (i32 i = 0; i < (1 << p); ++i) {
    if (popcnt (i) <= k) {
      ans += now[i].sum;
    }
  }
  free (now);
  free (next);
  return ans % mod;
}

void run (void) {
  i64 l = read_int();
  i64 r = read_int();
  i32 k = read_int();
  i64 ans = (calc (r, k) - calc (l - 1, k) + mod) % mod;
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}