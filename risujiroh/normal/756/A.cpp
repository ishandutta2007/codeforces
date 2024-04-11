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
  dsu d(n);
  for (int i = 0; i < n; ++i) {
    int p;
    cin >> p;
    --p;
    d.unite(i, p);
  }
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    cnt += b;
  }
  int res = cnt % 2 == 0;
  if (d.cc > 1) {
    res += d.cc;
  }
  cout << res << '\n';
}