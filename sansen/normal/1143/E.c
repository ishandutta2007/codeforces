#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

typedef struct rmq {
  i32 *a;
  i32 size;
} seg;

i32 min (i32 a, i32 b) {
  return a < b ? a : b;
}

seg* new_RMQ (const i32 n, const i32 *v) {
  i32 k = 1;
  while (k < n) k *= 2;
  seg *s = (seg *) calloc (1, sizeof (seg));
  s->a = (i32 *) calloc (2 * k, sizeof (i32));
  s->size = k;
  for (i32 i = 0; i < k; ++i) {
    s->a[i + k] = (i < n ? v[i] : 200000 + 1);
  }
  for (i32 i = k - 1; i >= 1; --i) {
    s->a[i] = min(s->a[2 * i], s->a[2 * i + 1]);
  }
  return s;
}

i32 query (seg *s, i32 l, i32 r) {
  i32 res = 200000 + 1;
  for (l += s->size, r += s->size; l < r; l >>= 1, r >>= 1) {
    if (l & 1) res = min (res, s->a[l++]);
    if (r & 1) res = min (res, s->a[--r]);
  }
  return res;
}

void run (void) {
  const i32 n = read_int();
  const i32 m = read_int();
  const i32 q = read_int();
  i32 *p = (i32 *) calloc (n, sizeof (i32));
  i32 *ip = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    p[i] = read_int() - 1;
    ip[p[i]] = i;
  }
  i32 *a = (i32 *) calloc (m, sizeof (i32));
  for (i32 i = 0; i < m; ++i) {
    a[i] = read_int() - 1;
  }
  i32 *index = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    index[i] = m;
  }
  i32 *next = (i32 *) calloc (m + 1, sizeof (i32));
  next[m] = m;
  for (i32 i = m - 1; i >= 0; --i) {
    next[i] = index[p[(ip[a[i]] + 1) % n]];
    index[a[i]] = i;
  }
  i32 *t = (i32 *) calloc (m + 1, sizeof (i32));
  i32 *s = (i32 *) calloc (m + 1, sizeof (i32));
  for (i32 i = 0; i < m + 1; ++i) {
    t[i] = i;
    s[i] = next[i];
  }
  i32 l = n - 1;
  while (l > 0) {
    if (l & 1) {
      for (i32 i = 0; i <= m; ++i) {
	t[i] = s[t[i]];
      }
    }
    for (i32 i = 0; i <=m; ++i) {
      s[i] = s[s[i]];
    }
    l >>= 1;
  }
  seg *dp = new_RMQ (m + 1, t);
  for (i32 i = 0; i < q; ++i) {
    i32 l = read_int() - 1;
    i32 r = read_int();
    i32 v = query (dp, l, r);
    putchar (v < r ? '1' : '0');
  }
  puts("");
}

int main (void) {
  run ();
  return 0;
}