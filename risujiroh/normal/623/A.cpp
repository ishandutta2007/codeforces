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
  int root(int v) {
    if (p[v] == -1) return v;
    return p[v] = root(p[v]);
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
  bool same(int u, int v) { return root(u) == root(v); }
  int size(int v) { return sz[root(v)]; }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<bitset<500>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u][v] = g[v][u] = 1;
  }
  dsu b(2 * n), d(n);
  for (int v = 0; v < n; ++v) {
    for (int u = 0; u < v; ++u) {
      if (g[u][v]) continue;
      if (b.same(u, v)) {
        cout << "No\n";
        exit(0);
      }
      b.unite(u, n + v);
      b.unite(n + u, v);
      d.unite(u, v);
    }
  }
  string res(n, 'b');
  int cnt = 0;
  for (int v = 0; v < n; ++v) {
    if (d.root(v) != v) continue;
    if (d.size(v) > 1) {
      if (cnt++) {
        cout << "No\n";
        exit(0);
      }
      for (int u = 0; u < n; ++u) {
        if (not d.same(u, v)) continue;
        res[u] = "ac"[b.same(u, v)];
      }
    }
  }
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < n; ++v) {
      if (res[u] != 'a' or res[v] != 'c') continue;
      if (g[u][v] == 1) {
        cout << "No\n";
        exit(0);
      }
    }
  }
  cout << "Yes\n";
  cout << res << '\n';
}