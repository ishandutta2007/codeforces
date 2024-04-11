#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct dsu {
  int cc;
  vector<int> p, sz, w, b;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1), w(n), b(n) {}
  int root(int v) const {
    while (p[v] != -1) v = p[v];
    return v;
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    --cc;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    w[u] += w[v];
    b[u] += b[v];
    return true;
  }
  bool same(int u, int v) const { return root(u) == root(v); }
  int size(int v) const { return sz[root(v)]; }
};

auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, lim;
  cin >> n >> m >> lim;
  dsu d(n);
  for (int v = 0; v < n; ++v) {
    cin >> d.w[v];
  }
  for (int v = 0; v < n; ++v) {
    cin >> d.b[v];
  }
  auto w = d.w, b = d.b;
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    d.unite(u, v);
  }
  vector dp(lim + 1, 0);
  for (int v = 0; v < n; ++v) {
    if (d.root(v) != v) continue;
    auto ndp = dp;
    for (int x = 0; x + d.w[v] <= lim; ++x) {
      ndp[x + d.w[v]] = max(ndp[x + d.w[v]], dp[x] + d.b[v]);
    }
    for (int u = 0; u < n; ++u) {
      if (not d.same(u, v)) continue;
      for (int x = 0; x + w[u] <= lim; ++x) {
        ndp[x + w[u]] = max(ndp[x + w[u]], dp[x] + b[u]);
      }
    }
    swap(dp, ndp);
    for (int x = 0; x < lim; ++x) {
      dp[x + 1] = max(dp[x + 1], dp[x]);
    }
  }
  cout << dp.back() << '\n';
}