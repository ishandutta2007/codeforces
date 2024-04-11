#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

struct UnionFind {
  const int n;
  V<> t; // root ? -sz : par
  UnionFind(int _n) : n(_n), t(n, -1) {}
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
  V<> d(n);
  while (m--) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
    ++d[u], ++d[v];
  }
  for (auto&& e : g) sort(begin(e), end(e));
  int x = min_element(begin(d), end(d)) - begin(d);
  V<> v0, v1;
  for (int v = 0; v < n; ++v) {
    if (binary_search(begin(g[x]), end(g[x]), v)) {
      v1.push_back(v);
    } else {
      v0.push_back(v);
    }
  }
  set<int> to(begin(v1), end(v1));
  for (int v : v0) {
    set<int> nto;
    for (int u : to) if (binary_search(begin(g[v]), end(g[v]), u)) {
      nto.insert(u);
    }
    swap(to, nto);
  }
  struct Edge { int u, v, w; };
  V<Edge> es;
  for (int v : v1) {
    int w = to.count(v);
    es.emplace_back(Edge{n, v, w});
  }
  for (int v : v1) for (int u : v1) if (u < v) {
    int w = binary_search(begin(g[v]), end(g[v]), u);
    es.emplace_back(Edge{u, v, w});
  }
  sort(begin(es), end(es), [&](const auto& el, const auto& er) { return el.w < er.w; });
  UnionFind uf(n + 1);
  for (int v : v0) {
    uf.unite(n, v);
  }
  int res = 0;
  for (const auto& e : es) {
    if (uf.same(e.u, e.v)) continue;
    uf.unite(e.u, e.v);
    res += e.w;
  }
  cout << res << '\n';
}