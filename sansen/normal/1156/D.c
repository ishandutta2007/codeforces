#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<inttypes.h>
#include<string.h>

typedef int64_t i64;
typedef int32_t i32;

static void print_int(i64 n){if(n<0){putchar('-');n=-n;}if(n==0){putchar('0');return;}int s[20],len=0;while(n>0){s[len++]=n%10+'0';n/=10;}while(len>0){putchar(s[--len]);}}
static i64 read_int(void){int prev='\0';int c=getchar();while(!('0'<=c && c<='9')){prev=c;c=getchar();}i64 res=0;while('0'<=c && c<='9'){res=10*res+c-'0';c=getchar();}return prev=='-'?-res:res;}

typedef struct union_find {
  int32_t *parent;
  int32_t size;
} union_find;

void init_union_find (union_find * const u) {
  for (int32_t i = 0; i < u->size; ++i){
    u->parent[i] = -1;
  }
}

union_find* new_union_find (const int32_t size) {
  union_find * const u = (union_find *) calloc (1, sizeof (union_find));
  u->parent = (int32_t *) calloc (size, sizeof (int32_t));
  u->size = size;
  init_union_find (u);
  return u;
}

void free_union_find (union_find * const u) {
  free (u->parent);
  free (u);
}

int32_t root (union_find * const u, int32_t x) {
  int32_t index[32];
  int32_t top = 0;
  while (u->parent[x] >= 0) {
    index[top++] = x;
    x = u->parent[x];
  }
  while (top > 0) {
    u->parent[index[--top]] = x;
  }
  return x;
}

int same (union_find * const u, const int32_t x, const int32_t y) {
  return root (u, x) == root (u, y);
}

int32_t get_size (union_find * const u, const int32_t x) {
  return - (u->parent[root (u, x)]);
}

void unite (union_find * const u, int32_t x, int32_t y) {
  x = root (u, x);
  y = root (u, y);
  if (x == y) return;
  if (u->parent[x] > u->parent[y]) {
    const int32_t swap = x;
    x = y;
    y = swap;
  }
  u->parent[x] += u->parent[y];
  u->parent[y] = x;
}

void run (void) {
  i32 n = read_int();
  union_find *u[2] = {new_union_find (n), new_union_find (n)};
  for (i32 i = 1; i < n; ++i) {
    i32 x = read_int() - 1;
    i32 y = read_int() - 1;
    i32 c = read_int();
    unite (u[c], x, y);
  }
  i64 ans = 0;
  uint8_t *used = (uint8_t *) calloc (n, sizeof (uint8_t));
  for (i32 k = 0; k < 2; ++k) {
    memset (used, 0, sizeof (uint8_t) * n);
    for (i32 i = 0; i < n; ++i) {
      i32 r = root (u[k], i);
      if (used[r]) continue;
      i32 size = get_size (u[k], i);
      ans += (i64) size * (size - 1);
      used[r] = 1;
    }
  }
  for (i32 i = 0; i < n; ++i) {
    ans += (i64) (get_size (u[0], i) - 1) * (get_size (u[1], i) - 1);
  }
  print_int (ans);
  puts ("");
}

int main (void) {
  run ();
  return 0;
}