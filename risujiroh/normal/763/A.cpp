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
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> c(n);
  for (auto&& e : c) cin >> e;
  dsu d(n);
  for (int v = 0; v < n; ++v) {
    for (int u : g[v]) {
      if (c[v] == c[u]) {
        d.unite(v, u);
      }
    }
  }
  for (int v = 0; v < n; ++v) {
    set<int> se{d.root(v)};
    for (int u : g[v]) {
      se.insert(d.root(u));
    }
    int cnt = 0;
    for (int p : se) {
      cnt += d.sz[p];
    }
    if (cnt < n) continue;
    cout << "YES\n";
    cout << v + 1 << '\n';
    exit(0);
  }
  cout << "NO\n";
}