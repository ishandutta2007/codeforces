#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <vector>
#include <cassert>
using namespace std;

#define LOG(f...) fprintf(stderr, f)

using ll = long long;

template<class T> void read(T &x) {
  char ch; x = 0;
  int f = 1;
  while (isspace(ch = getchar()));
  if (ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + (ch - '0'); while(isdigit(ch = getchar()));
  x *= f;
}
template<class T, class ...A> void read(T &x, A&... args) { read(x); read(args...); }

const int N = 100003, B = 317;
int fa[N], tag[B + 5], left[N];
bool empt[B + 5];
int n;

void build(int b) {
  if (empt[b]) return;
  int l = b * B, r = min(n, (b + 1) * B);
  if (tag[b] > B) {
    empt[b] = true;
    iota(left + l, left + r, l);
    return;
  }
  left[l] = l;
  for (int i = l + 1; i < r; ++i) {
    int f = max(0, fa[i] - tag[b]);
    if (f < l) left[i] = i;
    else left[i] = left[f];
  }
}
void modify(int l, int r, int d) {
  int bl = l / B, br = r / B;
  if (bl == br)
    for (int i = l; i <= r; ++i)
      fa[i] = max(0, fa[i] - d);
  else {
    for (int i = l, li = (bl + 1) * B; i < li; ++i)
      fa[i] = max(0, fa[i] - d);
    for (int i = bl + 1; i < br; ++i)
      tag[i] += d;
    for (int i = br * B; i <= r; ++i)
      fa[i] = max(0, fa[i] - d);
  }
  for (int i = bl; i <= br; ++i) build(i);
}

int LCA(int x, int y) {
  while (left[x] != left[y]) {
    int bx = x / B, by = y / B;
    if (by > bx) y = max(0, fa[left[y]] - tag[by]);
    else if (bx > by) x = max(0, fa[left[x]] - tag[bx]);
    else x = max(0, fa[left[x]] - tag[bx]), y = max(0, fa[left[y]] - tag[by]);
  }
  int bx = x / B;
  while (x != y) {
    if (x < y) swap(x, y);
    x = max(0, fa[x] - tag[bx]);
  }
  return x;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int q;
  read(n, q);
  for (int i = 1; i < n; ++i)
    read(fa[i]), --fa[i];
  for (int i = 0, li = (n - 1) / B; i <= li; ++i)
    build(i);
  while (q--) {
    int opt, l, r, d;
    read(opt, l, r);
    --l; --r;
    if (opt == 1) read(d), modify(l, r, d);
    else printf("%d\n", LCA(l, r) + 1);
  }
  return 0;
}