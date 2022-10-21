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
  int T; cin >> T;
  while (T--) {
    int n, m; cin >> n >> m;
    UnionFind uf(n), duf(2 * n);
    while (m--) {
      int u, v; cin >> u >> v, --u, --v;
      if (uf.same(u, v)) continue;
      uf.unite(u, v);
      duf.unite(u, n + v);
      duf.unite(n + u, v);
    }
    set<int> se0, se1;
    for (int v = 0; v < n; ++v) {
      if (duf.same(0, v)) se0.insert(v);
      else se1.insert(v);
    }
    if (se0.size() > se1.size()) swap(se0, se1);
    cout << se0.size() << '\n';
    bool f = true;
    for (int e : se0) {
      if (!f) cout << ' ';
      cout << e + 1;
      f = false;
    }
    cout << '\n';
  }
}