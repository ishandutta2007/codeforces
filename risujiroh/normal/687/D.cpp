#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

struct dsu {
  vector<int> p, sz;
  dsu(int n = 0) : p(n, -1), sz(n, 1) {}
  int root(int v) {
    if (p[v] == -1) return v;
    return p[v] = root(p[v]);
  }
  bool unite(int u, int v) {
    u = root(u), v = root(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }
  bool same(int u, int v) { return root(u) == root(v); }
  int size(int v) { return sz[root(v)]; }
  void reset() {
    fill(begin(p), end(p), -1);
    fill(begin(sz), end(sz), 1);
  }
};

template <class T> struct segtree {
  const int n;
  vector<T> t;
  segtree(int _n = 0) : n(_n), t(2 * n) {}
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i--; ) t[i] = t[2 * i] * t[2 * i + 1]; }
  T fold(int l, int r) const {
    T a, b;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = a * t[l++];
      if (r & 1) b = t[--r] * b;
    }
    return a * b;
  }
  void set(int i, T a) {
    t[i += n] = a;
    while (i >>= 1) t[i] = t[2 * i] * t[2 * i + 1];
  }
};

struct edge {
  int u, v, w;
  bool operator>(const edge& b) const {
    return w > b.w;
  }
};

struct node {
  static inline function<vector<edge>(vector<edge>)> select;
  vector<edge> edges;
  friend node operator*(const node& a, const node& b) {
    node c;
    merge(begin(a.edges), end(a.edges), begin(b.edges), end(b.edges), back_inserter(c.edges), greater<>());
    c.edges = select(c.edges);
    return c;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  dsu d(2 * n);
  node::select = [&](const vector<edge>& edges) {
    vector<edge> res;
    d.reset();
    for (auto&& e : edges) {
      if (d.same(e.u, n + e.v)) continue;
      res.push_back(e);
      if (d.same(e.u, e.v)) {
        return res;
      }
      d.unite(e.u, n + e.v);
      d.unite(n + e.u, e.v);
    }
    res.push_back({0, 0, -1});
    return res;
  };
  segtree<node> seg(m);
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    --u, --v;
    seg[i] = {{{u, v, w}}};
  }
  seg.build();
  while (q--) {
    int l, r;
    cin >> l >> r;
    --l;
    cout << seg.fold(l, r).edges.back().w << '\n';
  }
}