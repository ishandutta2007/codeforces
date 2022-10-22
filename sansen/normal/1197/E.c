#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

void msort_memcpy (uint8_t * restrict dst, uint8_t * restrict src, size_t size) {
  while (size--) {
    *dst++ = *src++;
  }
}

void msort (void * const array, const size_t num, const size_t size, int (* const cmp) (const void *, const void *)) {
  typedef struct operation {
    size_t l;
    size_t r;
    int32_t type;
  } op;
  uint8_t * const a = (uint8_t *) array;
  uint8_t * const tmp = (uint8_t *) malloc (size * num);
  op stack[64];
  int32_t top = 0;
  stack[top++] = (op) {0, num, 0};
  while (top > 0) {
    const op t = stack[--top];
    if (t.l + 1 >= t.r) continue;
    const size_t m = (t.l + t.r) / 2;
    if (t.type == 0) {
      stack[top++] = (op) {t.l, t.r, 1};
      stack[top++] = (op) {t.l, m  , 0};
      stack[top++] = (op) {m  , t.r, 0};
      continue;
    }
    msort_memcpy (tmp, a + t.l * size, (m - t.l) * size);
    size_t i = 0;
    size_t j = m * size;
    size_t k = t.l * size;
    while (i < (m - t.l) * size && j < t.r * size) {
      if (cmp (tmp + i, a + j) <= 0) {
        msort_memcpy (a + k, tmp + i, size);
        i += size;
      } else {
        msort_memcpy (a + k, a + j, size);
        j += size;
      }
      k += size;
    }
    msort_memcpy (a + k, tmp + i, (m - t.l) * size - i);
  }
  free (tmp);
}

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))
#define SORT(a,n,cmp) msort((a),(n),sizeof(*(a)),cmp)

int cmp_int (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

i32 to_index (i32 *z, i32 len, i32 v) {
  i32 l = 0;
  i32 r = len;
  while (r - l > 1) {
    i32 m = (l + r) / 2;
    if (z[m] <= v) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

typedef struct range {
  i32 a, b;
  i32 x, y;
} range;

int cmp_range (const void *a, const void *b) {
  i32 d = ((range *)a)->b - ((range *)b)->b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 n = read_int();
  range *p = ALLOC (n, range);
  i32 *z = ALLOC (2 * n, i32);
  for (i32 i = 0; i < n; ++i) {
    p[i].a = z[i] = read_int();
    p[i].b = z[i + n] = read_int();
  }
  SORT (p, n, cmp_range);
  SORT (z, 2 * n, cmp_int);
  i32 len = 1;
  for (i32 i = 1; i < 2 * n; ++i) {
    if (z[i] == z[len - 1]) continue;
    z[len++] = z[i];
  }
  for (i32 i = 0; i < n; ++i) {
    p[i].x = to_index (z, len, p[i].a);
    p[i].y = to_index (z, len, p[i].b);
  }
  const i32 mod = 1000000007;
  i32 *dp = ALLOC (len, i32);
  i32 *min = ALLOC (len, i32);
  uint8_t *elem = ALLOC (len, uint8_t);
  for (i32 i = 0; i < len; ++i) {
    min[i] = 1000000000 + 1;
  }
  i32 way = 1;
  i32 prev = 0;
  for (i32 i = 0, j = 0; i < len; ++i) {
    if (min[i] < prev) {
      way = dp[i];
      prev = min[i];
    } else if (min[i] == prev) {
      way = (way + dp[i]) % mod;
    }
    for (; j < n && p[j].y == i; ++j) {
      i32 d = prev + p[j].b - p[j].a;
      i32 x = p[j].x;
      if (d < min[x]) {
        min[x] = d;
        dp[x] = way;
        elem[x] = 1;
      } else if (d == min[x]) {
        dp[x] = (dp[x] + way) % mod;
      }
    }
  }
  i32 k = len - 1;
  for (i32 i = len - 1; i > p[n - 1].y; --i) {
    min[i] += z[i];
    if (elem[k] && min[k] > min[i]) {
      k = i;
    }
  }
  i64 ans = 0;
  for (i32 i = len - 1; i > p[n - 1].y; --i) {
    if (elem[i] && min[i] == min[k]) {
      ans += dp[i];
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