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
  VV<> g(n);
  while (m--) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return g[i].size() > g[j].size(); });
  UnionFind uf(n);
  for (int i : idx) {
    for (int j : g[i]) if (!uf.same(i, j)) {
      uf.unite(i, j);
      cout << i + 1 << ' ' << j + 1 << '\n';
    }
  }
}