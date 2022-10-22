#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

void add (i32 *bit, i32 index, i32 v) {
  i32 n = bit[0];
  index++;
  for (i32 i = index; i <= n; i += i & -i) {
    bit[i] += v;
  }
}

i32 sum (i32 *bit, i32 index) {
  index++;
  i32 res = 0;
  for (i32 i = index; i > 0; i -= i & -i) {
    res += bit[i];
  }
  return res;
}

i32 search (i32 *bit, i32 x) {
  i32 w = 0;
  i32 k = 1;
  i32 n = bit[0];
  while (2 * k <= n) k *= 2;
  for (; k > 0; k >>= 1) {
    if (w + k <= n && bit[w + k] < x) {
      x -= bit[w + k];
      w += k;
    }
  }
  return w;
}

void run (void) {
  i32 n = read_int();
  i32 *a = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    a[i] = read_int();
  }
  i32 *bit = (i32 *) calloc (n + 1, sizeof (i32));
  bit[0] = n;
  for (i32 i = 0; i < n; ++i) {
    i32 b = read_int();
    add (bit, b, 1);
  }
  i32 *c = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    i32 k = (n - a[i]) % n;
    if (sum (bit, k) - sum (bit, k - 1) > 0) {
      add (bit, k, -1);
      c[i] = 0;
      continue;
    }
    i32 v = sum (bit, k);
    if (v >= n - i) {
      v = 1;
    } else {
      v++;
    }
    i32 index = search (bit, v);
    add (bit, index, -1);
    c[i] = (a[i] + index) % n;
  }
  for (i32 i = 0; i < n; ++i) {
    print_int (c[i]);
    putchar (i == n - 1 ? '\n' : ' ');
  }
}

int main (void) {
  run ();
  return 0;
}