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
  UnionFind uf(n);
  while (m--) {
    int u, v; cin >> u >> v, --u, --v;
    uf.unite(u, v);
  }
  map<int, int> ls, rs;
  for (int i = 0; i < n; ++i) {
    rs[uf.find(i)] = i;
  }
  for (int i = n - 1; i >= 0; --i) {
    ls[uf.find(i)] = i;
  }
  struct LR { int l, r; };
  V<LR> v;
  for (const auto& e : ls) {
    v.emplace_back(LR{e.second, rs[e.first]});
  }
  sort(begin(v), end(v), [&](const auto& l, const auto& r) { return l.r < r.r; });
  int res = (int)ls.size() - 1;
  m = v.size();
  V<> mn(m + 1, 1e9);
  for (int i = m - 1; i >= 0; --i) {
    mn[i] = min(v[i].l, mn[i + 1]);
  }
  for (int i = 0; i < m - 1; ++i) {
    // cerr << v[i].l << ',' << v[i].r << '\n';
    res -= v[i].r < mn[i + 1];
  }
  cout << res << '\n';
}