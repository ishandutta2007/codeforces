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
  vector<int> ex(n);
  dsu d(n);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    --a;
    d.unite(i, a);
    if (exchange(ex[a], 1)) {
      cout << "-1\n";
      exit(0);
    }
  }
  long long res = 1;
  for (int i = 0; i < n; ++i) {
    int sz = d.size(i);
    res = lcm(res, sz & 1 ? sz : sz / 2);
  }
  cout << res << '\n';
}