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
  struct Edge { int u, v, w; };
  V<Edge> es(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v, w; cin >> u >> v >> w, --u, --v;
    es[i] = {u, v, w};
  }
  struct Q { int id, q; };
  V<Q> qs(m); 
  for (int i = 0; i < m; ++i) {
    int q; cin >> q;
    qs[i] = {i, q};
  }
  sort(begin(qs), end(qs), [](const Q& l, const Q& r) { return l.q < r.q; });
  V<lint> res(m, -1);
  UnionFind uf(n);
  lint t = 0;
  sort(begin(es), end(es), [](const Edge& l, const Edge& r) { return l.w < r.w; });
  auto itr = begin(es);
  for (const auto& e : qs) {
    while (itr != end(es) and itr->w <= e.q) {
      lint sz = uf.size(itr->u);
      t -= sz * (sz - 1) / 2;
      sz = uf.size(itr->v); 
      t -= sz * (sz - 1) / 2;
      uf.unite(itr->u, itr->v);
      sz = uf.size(itr->u);
      t += sz * (sz - 1) / 2;
      ++itr;
    }
    res[e.id] = t;
  }
  for (int i = 0; i < m; ++i) {
    cout << res[i] << " \n"[i == m - 1];
  }
}