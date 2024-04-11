#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

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

typedef struct node {
  i32 v, k;
} node;

int cmp_node (const void *a, const void *b) {
  i32 d = ((node *)a)->v - ((node *)b)->v;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 n = read_int();
  if (n <= 3) {
    puts ("1");
    return;
  }
  node *p = ALLOC (n, node);
  for (i32 i = 0; i < n; ++i) {
    p[i].v = read_int();
    p[i].k = i + 1;
  }
  SORT (p, n, cmp_node);
  i64 d = p[1].v - p[0].v;
  i64 x = p[0].v + 2 * d;
  i32 hit = 0;
  i32 k = 0;
  for (i32 i = 2; i < n; ++i) {
    if (p[i].v == x) {
      x += d;
    } else {
      hit++;
      k = i;
      
    }
  }
  if (hit <= 1) {
    print_int (p[k].k);
    puts ("");
    return;
  }
  d = p[2].v - p[0].v;
  x = p[0].v + 2 * d;
  hit = 1;
  k = 1;
  for (i32 i = 3; i < n; ++i) {
    if (p[i].v == x) {
      x += d;
    } else {
      hit++;
      k = i;
    }
  }
  if (hit <= 1) {
    print_int (p[k].k);
    puts ("");
    return;
  }
  d = p[2].v - p[1].v;
  x = p[1].v + 2 * d;
  hit = 1;
  k = 0;
  for (i32 i = 3; i < n; ++i) {
    if (p[i].v == x) {
      x += d;
    } else {
      hit++;
      k = i;
    }
  }
  if (hit <= 1) {
    print_int (p[k].k);
    puts ("");
    return;
  }
  puts ("-1");
}

int main (void) {
  run ();
  return 0;
}