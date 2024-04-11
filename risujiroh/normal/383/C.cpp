#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> struct tree {
  struct edge {
    int u, v;
    T w;
  };
  const int n;
  vector<edge> es;
  vector<vector<int>> g;
  vector<int> pv, pe, sz, dep, vs, in, out, head;
  vector<T> dist;
  tree(int _n = 0) : n(_n), g(n) {}
  void add(int u, int v, T w = 1) {
    g[u].push_back(es.size()), g[v].push_back(es.size());
    es.push_back({u, v, w});
  }
  int other(int id, int v) const { return es[id].u ^ es[id].v ^ v; }
  void dfs(int v) {
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = other(id, v);
      assert(pv[to] == -1);
      pv[to] = v, pe[to] = id;
      dep[to] = dep[v] + 1, dist[to] = dist[v] + es[id].w;
      dfs(to);
      sz[v] += sz[to];
    }
    sort(begin(g[v]), end(g[v]), [&](int a, int b) {
      return sz[other(a, v)] * (a != pe[v]) > sz[other(b, v)] * (b != pe[v]);
    });
  }
  void build(int r = 0) {
    assert((int)es.size() == n - 1);
    pv.assign(n, -1), pe.resize(n), sz.resize(n), dep.resize(n), dist.resize(n);
    pe[r] = -1, dep[r] = 0, dist[r] = 0;
    dfs(r);
  }
  void dfs_hld(int v) {
    in[v] = vs.size(), vs.push_back(v);
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = other(id, v);
      head[to] = to == other(g[v][0], v) ? head[v] : to;
      dfs_hld(to);
    }
    out[v] = vs.size();
  }
  void build_hld(int r = 0) {
    build(r);
    vs.clear(), in.resize(n), out.resize(n), head.resize(n);
    head[r] = r;
    dfs_hld(r);
  }
  bool anc(int u, int v) const { return in[u] <= in[v] and out[v] <= out[u]; }
  int lca(int u, int v) const {
    while (true) {
      if (in[u] > in[v]) swap(u, v);
      if (head[u] == head[v]) return u;
      v = pv[head[v]];
    }
  }
  int d(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
  T len(int u, int v) const { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }
  int la(int v, int d) const {
    assert(0 <= d and d <= dep[v]);
    while (dep[head[v]] > d) v = pv[head[v]];
    return vs[in[head[v]] + (d - dep[head[v]])];
  }
  int next(int from, int to) const {
    assert(from != to);
    if (not anc(from, to)) return pv[from];
    return la(to, dep[from] + 1);
  }
  vector<pair<int, int>> ascend(int from, int to) const {
    vector<pair<int, int>> res;
    while (head[from] != head[to]) {
      res.emplace_back(in[from], in[head[from]]);
      from = pv[head[from]];
    }
    if (from != to) res.emplace_back(in[from], in[to] + 1);
    return res;
  }
  vector<pair<int, int>> descend(int from, int to) const {
    if (from == to) return {};
    if (head[from] == head[to]) return {{in[from] + 1, in[to]}};
    auto res = descend(from, pv[head[to]]);
    res.emplace_back(in[head[to]], in[to]);
    return res;
  }
  template <class F> void run(int from, int to, F f, bool vertex = true) const {
    int v = lca(from, to);
    for (auto e : ascend(from, v)) f(e.first + 1, e.second);
    if (vertex) f(in[v], in[v] + 1);
    for (auto e : descend(v, to)) f(e.first, e.second + 1);
  }
};

template <class T, class F> struct lazy_segtree {
  const int n;
  vector<T> t;
  vector<F> d;
  lazy_segtree(int _n = 0) : n(_n), t(2 * n), d(n) {}
  T& operator[](int i) { return t[n + i]; }
  void build() { for (int i = n; i--; ) t[i] = t[2 * i] * t[2 * i + 1]; }
  void apply(int i, F f) {
    t[i] = f(t[i]);
    if (i < n) d[i] = d[i] * f;
  }
  void push(int i) {
    apply(2 * i, d[i]), apply(2 * i + 1, d[i]);
    d[i] = F();
  }
  void push_down(int i) {
    for (int h = __lg(i), tz = __builtin_ctz(i); h > tz; --h) push(i >> h);
  }
  void pull_up(int i) {
    while (i >>= 1) t[i] = t[2 * i] * t[2 * i + 1];
  }
  T fold(int l, int r) {
    push_down(l += n), push_down(r += n);
    T a, b;
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = a * t[l++];
      if (r & 1) b = t[--r] * b;
    }
    return a * b;
  }
  T get(int i) { return fold(i, i + 1); }
  void act(int l, int r, F f) {
    push_down(l += n), push_down(r += n);
    for (int i = l, j = r; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(i++, f);
      if (j & 1) apply(--j, f);
    }
    pull_up(l >> __builtin_ctz(l)), pull_up(r >> __builtin_ctz(r));
  }
  void set(int i, T a) {
    push_down(i += n), push_down(i + 1);
    t[i] = a;
    pull_up(i);
  }
};

struct node {
  int v = 0, c = 0;
  node operator*(node b) const {
    return {v + b.v, c + b.c};
  }
};
struct add {
  int v = 0;
  add operator*(add g) const {
    return {v + g.v};
  }
  node operator()(node x) const {
    x.v += v * x.c;
    return x;
  }
};

template <class T, class Op = multiplies<T>>
constexpr T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  tree<int> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  g.build_hld();
  lazy_segtree<node, add> seg(n);
  for (int v = 0; v < n; ++v) {
    seg[g.in[v]] = {a[v], power(-1, g.dep[v])};
  }
  seg.build();
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int v, x;
      cin >> v >> x;
      --v;
      seg.act(g.in[v], g.out[v], {power(-1, g.dep[v]) * x});
    } else {
      int v;
      cin >> v;
      --v;
      cout << seg.get(g.in[v]).v << '\n';
    }
  }
}