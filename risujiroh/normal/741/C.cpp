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
  vector<int> a(n), b(n);
  dsu d(4 * n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
    d.unite(a[i], 2 * n + b[i]);
    d.unite(2 * n + a[i], b[i]);
  }
  for (int i = 0; i < 2 * n; i += 2) {
    int j = i + 1;
    d.unite(i, 2 * n + j);
    d.unite(2 * n + i, j);
  }
  for (int i = 0; i < 2 * n; ++i) {
    if (d.same(i, 0) or d.same(2 * n + i, 0)) continue;
    d.unite(i, 0);
  }
  for (int i = 0; i < n; ++i) {
    cout << d.same(a[i], 0) + 1 << ' ' << d.same(b[i], 0) + 1 << '\n';
  }
}