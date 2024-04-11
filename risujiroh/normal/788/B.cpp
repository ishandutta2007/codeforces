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
  vector<int> deg(n);
  long long c = 0;
  dsu d(n);
  vector<bool> b(n);
  for (int _ = m; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (u == v) {
      ++c;
      b[u] = true;
    } else {
      d.unite(u, v);
      ++deg[u];
      ++deg[v];
    }
  }
  {
    set<int> se;
    for (int v = 0; v < n; ++v) {
      if (deg[v] or b[v]) {
        se.insert(d.root(v));
      }
    }
    if (size(se) > 1) {
      cout << "0\n";
      exit(0);
    }
  }
  auto res = 0LL;
  for (int v = 0; v < n; ++v) {
    long long k = deg[v];
    res += k * (k - 1) / 2;
  }
  res += c * m - c - c * (c - 1) / 2;
  cout << res << '\n';
}