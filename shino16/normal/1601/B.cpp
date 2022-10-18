#line 2 "lib/prelude.hpp"
#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep2(i, m, n) for (auto i = (m); i < (n); i++)
#define rep(i, n) rep2(i, 0, n)
#define repr2(i, m, n) for (auto i = (n); i-- > (m);)
#define repr(i, n) repr2(i, 0, n)
#define all(x) begin(x), end(x)
#line 2 "main.cpp"

int n, a[300001], b[300001];
vector<int> G[300001*3];
int dist[300001*3], prv[300001*3];
int togo[300001*3*2], *f = togo + 300001*3, *l = f;

void add(int u, int l, int r) {
  for (u += n * 2, l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) G[u].push_back(l++);
    if (r & 1) G[u].push_back(--r);
  }
}

int main() {
  scanf("%d", &n);
  n++;
  rep2(i, 1, n) scanf("%d", a+i);
  rep2(i, 1, n) scanf("%d", b+i);

  rep2(i, 1, n) G[i].push_back(i*2), G[i].push_back(i*2+1);
  rep2(i, 1, n) G[i+n].push_back(i+b[i]+n*2);

  rep2(i, 1, n) add(i, i-a[i], i);

  fill(all(dist), 1 << 30);
  dist[n-1+n*2] = 0;
  *l++ = n-1+n*2;

  while (f != l) {
    int v = *f++;
    if (v == 0 + n) break;
    int d = dist[v] + (v >= n*2);
    for (auto u : G[v]) if (dist[u] > d) {
      dist[u] = d;
      prv[u] = v;
      if (v >= n*2) *l++ = u;
      else *--f = u;
    }
  }
  if (dist[0 + n] == 1 << 30) return printf("-1\n"), 0;
  printf("%d\n", dist[0 + n]);
  int v = 0 + n;
  vector<int> path = {v};
  while (v != n-1+n*2) {
    v = prv[v];
    if (n <= v && v < n*2) path.push_back(v);
  }
  assert(dist[n] == path.size());
  reverse(all(path));
  rep(i, size(path)) printf("%d%c", path[i]-n, " \n"[i==size(path)-1]);
}