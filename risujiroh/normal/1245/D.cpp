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
  int n; cin >> n;
  V<> x(n), y(n); for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  V<> c(n); for (auto&& e : c) cin >> e;
  V<> k(n); for (auto&& e : k) cin >> e;
  struct Edge { int u, v; lint w; };
  V<Edge> es;
  for (int v = 0; v < n; ++v) {
    es.emplace_back(Edge{v, n, c[v]});
  }
  for (int v = 0; v < n; ++v) for (int u = 0; u < v; ++u) {
    es.emplace_back(Edge{u, v, (lint)(k[u] + k[v]) * (abs(x[u] - x[v]) + abs(y[u] - y[v]))});
  }
  UnionFind uf(n + 1);
  sort(begin(es), end(es), [&](const Edge& l, const Edge& r) { return l.w < r.w; });
  lint res = 0;
  V<> vs;
  V< array<int, 2> > a;
  for (const auto& e : es) {
    if (uf.same(e.u, e.v)) continue;
    uf.unite(e.u, e.v);
    if (e.v == n) {
      vs.push_back(e.u);
    } else {
      a.emplace_back(array<int, 2>{e.u, e.v});
    }
    res += e.w;
  }
  cout << res << '\n';
  int m = vs.size();
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << vs[i] + 1 << " \n"[i == m - 1];
  }
  cout << a.size() << '\n';
  for (const auto& e : a) {
    cout << e[0] + 1 << ' ' << e[1] + 1 << '\n';
  }
}