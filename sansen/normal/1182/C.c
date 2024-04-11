#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

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

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))
#define ALLOC(size,type) ((type*)calloc((size),sizeof(type)))

typedef struct word {
  char *s;
  i32 num;
  i32 last;
} word;

int cmp_word (const void *a, const void *b) {
  const word *p = a;
  const word *q = b;
  i32 d = p->num - q->num;
  if (d != 0) return d < 0 ? -1 : 1;
  d = p->last - q->last;
  return d == 0 ? 0 : d < 0 ? -1 : 1;
}

typedef struct pair_word {
  word a, b;
} pair_word;

void run (void) {
  i32 n;
  scanf ("%" SCNi32, &n);
  char *s = ALLOC (n + 1000000, char);
  word *p = ALLOC (n, word);
  for (i32 i = 0; i < n; ++i) {
    scanf ("%s", s);
    i32 cnt = 0;
    i32 last = -1;
    for (i32 j = 0; s[j] != '\0'; ++j) {
      char vowel[] = "aiueo";
      for (i32 k = 0; k < 5; ++k) {
        if (s[j] == vowel[k]) {
          cnt++;
          last = k;
        }
      }
    }
    p[i].s = s;
    s += strlen (s) + 1;
    p[i].num = cnt;
    p[i].last = last;
  }
  msort (p, n, sizeof (*p), cmp_word);
  pair_word *a = ALLOC (n, pair_word);
  i32 alen = 0;
  const i32 inf = 1000000 + 1;
  for (i32 i = 0; i + 1 < n;) {
    if (cmp_word (p + i, p + i + 1) != 0) {
      ++i;
      continue;
    }
    a[alen++] = (pair_word) {p[i], p[i + 1]};
    p[i].num = p[i + 1].num = inf;
    i += 2;
  }
  qsort (p, n, sizeof (*p), cmp_word);
  while (n > 0 && p[n - 1].num == inf) --n;
  pair_word *b = ALLOC (n, pair_word);
  i32 blen = 0;
  for (i32 i = 0; i + 1 < n;) {
    if (p[i].num != p[i + 1].num) {
      ++i;
      continue;
    }
    b[blen++] = (pair_word) {p[i], p[i + 1]};
    i += 2;
  }
  i32 ans = MIN(alen, (alen + blen) / 2);
  printf ("%" PRIi32 "\n", ans);
  while (ans--) {
    if (blen > 0) {
      --blen;
      --alen;
      printf ("%s %s\n", b[blen].a.s, a[alen].a.s);
      printf ("%s %s\n", b[blen].b.s, a[alen].b.s);
    } else {
      alen -= 2;
      printf ("%s %s\n", a[alen].a.s, a[alen + 1].a.s);
      printf ("%s %s\n", a[alen].b.s, a[alen + 1].b.s);
    }
  }
}

int main (void) {
  run ();
  return 0;
}