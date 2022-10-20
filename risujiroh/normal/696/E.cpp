#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T = int> struct tree {
  struct edge {
    int from, to;
    T w;
    int operator-(int v) const { return from ^ to ^ v; }
  };
  int n;
  vector<edge> es;
  vector<vector<int>> g;
  vector<int> pv, pe, sz, dep, vs, in, out, head;
  vector<T> dist;
  tree(int _n = 0) : n(_n), g(n) {}
  void add(int u, int v, T w = 1) {
    g[u].push_back(size(es)), g[v].push_back(size(es));
    es.push_back({u, v, w});
  }
  void dfs(int v) {
    sz[v] = 1;
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = es[id] - v;
      assert(pv[to] == -1);
      pv[to] = v, pe[to] = id;
      dep[to] = dep[v] + 1, dist[to] = dist[v] + es[id].w;
      dfs(to);
      sz[v] += sz[to];
    }
    sort(begin(g[v]), end(g[v]), [&](int a, int b) {
      return sz[es[a] - v] * (a != pe[v]) > sz[es[b] - v] * (b != pe[v]);
    });
  }
  void build(int r = 0) {
    assert((int)size(es) == n - 1);
    pv.assign(n, -1), pe.resize(n), sz.resize(n), dep.resize(n), dist.resize(n);
    pe[r] = -1, dep[r] = 0, dist[r] = 0;
    dfs(r);
  }
  void dfs_hld(int v) {
    in[v] = size(vs), vs.push_back(v);
    for (int id : g[v]) {
      if (id == pe[v]) continue;
      int to = es[id] - v;
      head[to] = to == es[g[v][0]] - v ? head[v] : to;
      dfs_hld(to);
    }
    out[v] = size(vs);
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
  int len(int u, int v) const { return dep[u] + dep[v] - 2 * dep[lca(u, v)]; }
  T d(int u, int v) const { return dist[u] + dist[v] - 2 * dist[lca(u, v)]; }
  int la(int v, int d) const {
    assert(0 <= d and d <= dep[v]);
    while (dep[head[v]] > d) v = pv[head[v]];
    return vs[in[head[v]] + (d - dep[head[v]])];
  }
  int next(int from, int to) const {
    if (not anc(from, to)) return pv[from];
    return la(to, dep[from] + 1);
  }
  int next(int from, int to, int m) const {
    int v = lca(from, to);
    if (m <= dep[from] - dep[v]) return la(from, dep[from] - m);
    return la(to, m - dep[from] + 2 * dep[v]);
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

using ll = long long;

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

struct girl {
  ll w = inf<ll>;
  int v = -1, id = -1;
  bool operator<(const girl& b) const {
    return make_pair(w, v) < make_pair(b.w, b.v);
  }
};

struct node {
  girl g;
  ll off = 0;
  node operator*(const node& b) {
    girl ga = g, gb = b.g;
    ga.w += off;
    gb.w += b.off;
    return {min(ga, gb), 0};
  }
};
struct add {
  ll v = 0;
  add operator*(add b) const {
    return {v + b.v};
  }
  node operator()(node x) const {
    x.off += v;
    return x;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m, q;
  cin >> n >> m >> q;
  tree g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  g.build_hld();
  vector<vector<girl>> girls(n, {girl()});
  for (int id = 0; id < m; ++id) {
    int v;
    cin >> v;
    --v;
    girls[v].push_back({id + 1, v, id});
  }
  lazy_segtree<node, add> seg(n);
  for (int v = 0; v < n; ++v) {
    sort(rbegin(girls[v]), rend(girls[v]));
    seg[g.in[v]] = {girls[v].back(), 0};
  }
  seg.build();
  while (q--) {
    int t, v;
    cin >> t >> v;
    --v;
    if (t == 1) {
      int u, k;
      cin >> u >> k;
      --u;
      vector<int> res;
      while (k--) {
        girl mn;
        g.run(v, u, [&](int l, int r) {
          tie(l, r) = minmax({l, r});
          mn = min(mn, seg.fold(l, r).g);
        });
        if (mn.w >= inf<ll>) break;
        res.push_back(mn.id);
        ll to_add = mn.w - girls[mn.v].back().w;
        girls[mn.v].pop_back();
        girl ng = girls[mn.v].back();
        ng.w += to_add;
        seg.set(g.in[mn.v], {ng, 0});
      }
      cout << size(res);
      for (int e : res) {
        cout << ' ' << e + 1;
      }
      cout << '\n';
    } else {
      int k;
      cin >> k;
      seg.act(g.in[v], g.out[v], {k});
    }
  }
}