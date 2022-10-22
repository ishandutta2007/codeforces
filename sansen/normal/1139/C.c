#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

typedef struct UnionFind {
  int32_t *parent;
  int32_t size;
} UnionFind;

void initUnionFind (UnionFind *u) {
  for (int32_t i = 0; i < u->size; ++i){
    u->parent[i] = -1;
  }
}

UnionFind* newUnionFind (const int32_t size) {
  UnionFind *u = (UnionFind *) calloc (1, sizeof (UnionFind));
  u->parent = (int32_t *) calloc (size, sizeof (int32_t));
  u->size = size;
  initUnionFind (u);
  return u;
}

void freeUnionFind (UnionFind *u) {
  free (u->parent);
  free (u);
}

int32_t root (UnionFind *u, int32_t x) {
  int32_t index[32];
  int32_t len = 0;
  while (u->parent[x] >= 0) {
    index[len++] = x;
    x = u->parent[x];
  }
  while (len > 0) {
    u->parent[index[--len]] = x;
  }
  return x;
}

int same (UnionFind *u, int32_t x, int32_t y) {
  return root (u, x) == root (u, y);
}

int32_t getSize(UnionFind *u, int32_t x) {
  return - (u->parent[root (u, x)]);
}

void unite(UnionFind *u, int32_t x, int32_t y) {
  x = root (u, x);
  y = root (u, y);
  if (x == y) return;
  if (u->parent[x] > u->parent[y]) {
    int32_t swap = x;
    x = y;
    y = swap;
  }
  u->parent[x] += u->parent[y];
  u->parent[y] = x;
}

const i32 mod = 1000000007;

i32 modPow (i32 r, i32 n) {
  i32 t = 1;
  i32 s = r;
  while (n > 0) {
    if (n & 1) {
      t = (i64) t * s % mod;
    }
    s = (i64) s * s % mod;
    n >>= 1;
  }
  return t;
}

void run (void) {
  const i32 n = read_int();
  const i32 k = read_int();
  UnionFind *u = newUnionFind (n);
  for (i32 i = 1; i < n; ++i) {
    i32 a = read_int() - 1;
    i32 b = read_int() - 1;
    i32 c = read_int();
    if (c == 0) {
      unite (u, a, b);
    }
  }
  i32 ans = modPow (n, k);
  uint8_t *used = (uint8_t *) calloc (n, sizeof (uint8_t));
  for (i32 i = 0; i < n; ++i) {
    i32 r = root (u, i);
    if (used[r]) continue;
    used[r] = 1;
    i32 m = getSize (u, i);
    ans = (ans + mod - modPow (m, k)) % mod;
  }
  print_int (ans);
  puts("");
}

int main (void) {
  run ();
  return 0;
}