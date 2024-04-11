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
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  dsu d(2 * n + 1), g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    d.unite(u, n + v);
    d.unite(n + u, v);
    g.unite(u, v);
  }
  for (int v = 0; v < n; ++v) {
    if (d.same(v, n + v)) {
      cout << "NO\n";
      exit(0);
    }
    if (d.same(v, 2 * n) or d.same(n + v, 2 * n)) continue;
    d.unite(v, 2 * n);
  }
  vector<int> a(n), b(n);
  for (int v = 0; v < n; ++v) {
    ++(d.same(v, 2 * n) ? a : b)[g.root(v)];
  }
  DEBUG(a);
  DEBUG(b);
  constexpr int lim = 5000;
  vector<bitset<lim + 1>> dp(n + 1);
  dp[n][0] = 1;
  for (int i = n; i--; ) {
    dp[i] = dp[i + 1] << a[i] | dp[i + 1] << b[i];
  }
  if (dp[0][n2] == 0) {
    cout << "NO\n";
    exit(0);
  }
  vector<bool> f(n);
  for (int i = 0; i < n; ++i) {
    if (n2 >= a[i] and dp[i + 1][n2 - a[i]]) {
      f[i] = true;
      n2 -= a[i];
    } else {
      assert(dp[i + 1][n2 - b[i]]);
      n2 -= b[i];
    }
  }
  cout << "YES\n";
  for (int v = 0; v < n; ++v) {
    if (d.same(v, 2 * n) ^ f[g.root(v)]) {
      cout << (n1-- > 0 ? '1' : '3');
    } else {
      cout << '2';
    }
  }
  cout << '\n';
}