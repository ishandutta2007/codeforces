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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector a(2, vector<int>(n));
    vector<vector<pair<int, int>>> pos(n);
    bool ok = true;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
        --a[i][j];
        pos[a[i][j]].emplace_back(i, j);
        ok &= size(pos[a[i][j]]) <= 2;
      }
    }
    if (not ok) {
      cout << "-1\n";
      continue;
    }
    dsu d(2 * n), g(n);
    for (auto&& e : pos) {
      auto [i0, j0] = e[0];
      auto [i1, j1] = e[1];
      if (i0 == i1) {
        d.unite(j0, n + j1);
        d.unite(n + j0, j1);
      } else {
        d.unite(j0, j1);
        d.unite(n + j0, n + j1);
      }
      g.unite(j0, j1);
    }
    for (int v = 0; v < n; ++v) {
      if (d.same(0, v) and d.same(0, n + v)) {
        ok = false;
        break;
      }
      if (d.same(0, v) or d.same(0, n + v)) continue;
    }
    vector<array<int, 2>> cnt(n);
    for (int v = 0; v < n; ++v) {
      int r = g.root(v);
      ++cnt[r][d.same(r, v)];
    }
    vector<int> res;
    for (int v = 0; v < n; ++v) {
      int r = g.root(v);
      if (cnt[r][0] < cnt[r][1]) {
        if (not d.same(r, v)) {
          res.push_back(v);
        }
      } else {
        if (d.same(r, v)) {
          res.push_back(v);
        }
      }
    }
    int m = size(res);
    cout << m << '\n';
    for (int i = 0; i < m; ++i) {
      cout << res[i] + 1 << " \n"[i == m - 1];
    }
  }
}