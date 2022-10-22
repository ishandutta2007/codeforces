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

int cmp_int (const void *a, const void *b) {
  i32 d = *(i32 *)a - *(i32 *)b;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

void run (void) {
  i32 q = read_int();
  while (q--) {
    i32 n = read_int();
    i32 *a = ALLOC (n, i32);
    for (i32 i = 0; i < n; ++i) {
      a[i] = read_int();
    }
    msort (a, n, sizeof (i32), cmp_int);
    i32 *cnt = ALLOC (n, i32);
    i32 len = 0;
    for (i32 i = 0; i < n;) {
      i32 j = i;
      while (j < n && a[i] == a[j]) {
        cnt[len]++;
        ++j;
      }
      len++;
      i = j;
    }
    msort (cnt, len, sizeof (i32), cmp_int);
    i32 ans = 0;
    i32 prev = n + 1;
    for (i32 i = len - 1; i >= 0 && prev > 1; --i) {
      if (cnt[i] < prev) {
        ans += cnt[i];
        prev = cnt[i];
      } else {
        ans += prev - 1;
        prev--;
      }
    }
    print_int (ans);
    puts ("");
    free (a);
    free (cnt);
  }
}

int main (void) {
  run ();
  return 0;
}