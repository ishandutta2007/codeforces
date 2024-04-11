#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct UnionFind {
  const int n;
  V<> t; // root ? -sz : par
  UnionFind(int n) : n(n), t(n, -1) {}
  int find(int v) { return t[v] < 0 ? v : t[v] = find(t[v]); }
  void unite(int u, int v) {
    if ((u = find(u)) == (v = find(v))) return;
    if (-t[u] < -t[v]) swap(u, v);
    t[u] += t[v];
    t[v] = u;
  }
  bool same(int u, int v) { return find(u) == find(v); }
  int size(int v) { return -t[find(v)]; }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  UnionFind uf(n);
  V<> x(m), y(m); 
  for (int i = 0; i < m; ++i) {
    cin >> x[i] >> y[i], --x[i], --y[i];
    uf.unite(x[i], y[i]);
  }
  V<> a(n);
  for (int i = 0; i < m; ++i) {
    ++a[uf.find(x[i])];
  }
  V<bool> b(n);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int p = uf.find(i);
    if (b[p]) continue;
    b[p] = true;
    res += min(a[p], uf.size(p) - 1);
  }
  res = m - res;
  cout << res << '\n';
}