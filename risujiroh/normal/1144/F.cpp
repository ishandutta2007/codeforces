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
  V< pair<int, int> > edges;
  UnionFind uf(2 * n);
  for (int _ = 0; _ < m; ++_) {
    int u, v; cin >> u >> v, --u, --v;
    edges.emplace_back(u, v);
    uf.unite(u, n + v);
    uf.unite(n + u, v);
  }
  for (int v = 0; v < n; ++v) if (uf.same(v, n + v)) {
    return cout << "NO" << '\n', 0;
  }
  cout << "YES" << '\n';
  for (int i = 0; i < m; ++i) {
    int u = edges[i].first;
    int v = edges[i].second;
    if (uf.same(0, u)) {
      cout << '1';
    } else {
      cout << '0';
    }
  }
  cout << '\n';
}