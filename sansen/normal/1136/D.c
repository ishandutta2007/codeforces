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

typedef struct node {
  i32 u, v;
} node;

int cmp (const void *a, const void *b) {
  node *p = (node *)a;
  node *q = (node *)b;
  i32 d = p->u - q->u;
  if (d != 0)  return d < 0 ? -1 : 1;
  d = p->v - q->v;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

i32 find (node *q, i32 len, const node *v) {
  if (len == 0) return -1;
  if (cmp (v, q) < 0) return -1;
  i32 l = 0;
  i32 r = len;
  while (r - l > 1) {
    i32 m = (l + r) / 2;
    if (cmp (v, q + m) < 0) {
      r = m;
    } else {
      l = m;
    }
  }
  return l;
}

void run (void) {
  const i32 n = read_int();
  const i32 m = read_int();
  i32 *p = (i32 *) calloc (n, sizeof (i32));
  i32 *inv_p = (i32 *) calloc (n, sizeof (i32));
  for (i32 i = 0; i < n; ++i) {
    p[i] = read_int() - 1;
    inv_p[p[i]] = i;
  }
  node *q = (node *) calloc (m, sizeof (node));
  for (i32 i = 0; i < m; ++i) {
    i32 u = read_int() - 1;
    i32 v = read_int() - 1;
    q[i] = (node) {u, v};
  }
  qsort (q, m, sizeof (node), cmp);
  i32 *r = (i32 *) calloc (n, sizeof (i32));
  i32 len = 0;
  for (i32 i = n - 2; i >= 0; --i) {
    node t = {p[i], p[n - 1]};
    i32 k = find (q, m, &t);
    if (!(0 <= k && k < m && cmp(q + k, &t) == 0)) {
      r[len++] = p[i];
      continue;
    }
    for (i32 j = 0; j < len; ++j) {
      node t = {p[i], r[j]};
      i32 k = find (q, m, &t);
      if (!(0 <= k && k < m && cmp(q + k, &t) == 0)) {
	r[len++] = p[i];
	break;
      }
    }
  }
  print_int (n - 1 - len);
  puts("");
}

int main (void) {
  run ();
  return 0;
}