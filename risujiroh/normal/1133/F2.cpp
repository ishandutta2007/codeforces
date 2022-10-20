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
  int n, m, D; cin >> n >> m >> D;
  VV<> g(n);
  while (m--) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  UnionFind uf(n);
  int x = 0;
  set<int> se;
  for (int i = n - 1; i >= 0; --i) {
    for (int j : g[i]) if (j and !uf.same(i, j)) {
      uf.unite(i, j);
      x += i == 0;
      if (i == 0) se.insert(j);
    }
  }
  if (D < x or D > g[0].size()) return cout << "NO" << '\n', 0;
  cout << "YES" << '\n';
  UnionFind nuf(n);
  for (int j : se) {
    nuf.unite(0, j);
    cout << 1 << ' ' << j + 1 << '\n';
  }
  for (int j : g[0]) if (!nuf.same(0, j)) {
    if (D-- == se.size()) break;
    nuf.unite(0, j);
    cout << 1 << ' ' << j + 1 << '\n';
  }
  for (int i = 1; i < n; ++i) {
    for (int j : g[i]) if (j and !nuf.same(i, j)) {
      nuf.unite(i, j);
      cout << i + 1 << ' ' << j + 1 << '\n';
    }
  }
}