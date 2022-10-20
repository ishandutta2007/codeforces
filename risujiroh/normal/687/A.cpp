#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct dsu {
  int cc;
  vector<int> p, sz;
  dsu(int n = 0) : cc(n), p(n, -1), sz(n, 1) {}
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
    return true;
  }
  bool same(int u, int v) const { return root(u) == root(v); }
  int size(int v) const { return sz[root(v)]; }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  dsu d(2 * n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    d.unite(u, n + v);
    d.unite(n + u, v);
  }
  for (int v = 0; v < n; ++v) {
    if (d.same(v, n + v)) {
      cout << "-1\n";
      exit(0);
    }
    if (d.same(0, v) or d.same(0, n + v)) continue;
    d.unite(0, v);
  }
  vector<vector<int>> res(2);
  for (int v = 0; v < n; ++v) {
    res[d.same(0, v)].push_back(v);
  }
  for (auto&& v : res) {
    int k = size(v);
    cout << k << '\n';
    for (int i = 0; i < k; ++i) {
      cout << v[i] + 1 << " \n"[i == k - 1];
    }
  }
}