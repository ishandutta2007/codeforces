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

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

template <class T> struct mini {
  T v = inf<T>;
  mini operator*(mini b) const {
    return b.v < v ? b : *this;
  }
};
struct chmin {
  int v = inf<int>;
  chmin operator*(chmin g) const {
    return {min(v, g.v)};
  }
  mini<int> operator()(mini<int> x) const {
    return {min(x.v, v)};
  }
};

struct seg_t {
  int n;
  vector<vector<int>> v;
  seg_t(int _n) : n(_n), v(2 * n) {}
  void add(int x, int y) {
    v[n + x].push_back(y);
  }
  void build() {
    for (int i = n; i < 2 * n; ++i) {
      sort(begin(v[i]), end(v[i]));
      v[i].erase(unique(begin(v[i]), end(v[i])), end(v[i]));
    }
    for (int i = n; i-- > 1; ) {
      v[i].resize(size(v[2 * i]) + size(v[2 * i + 1]));
      merge(begin(v[2 * i]), end(v[2 * i]), begin(v[2 * i + 1]), end(v[2 * i + 1]), begin(v[i]));
      v[i].erase(unique(begin(v[i]), end(v[i])), end(v[i]));
    }
  }
  int lb(int l, int r, int y) {
    int res = inf<int>;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        auto it = lower_bound(begin(v[l]), end(v[l]), y);
        if (it != end(v[l])) {
          res = min(res, *it);
        }
        ++l;
      }
      if (r & 1) {
        --r;
        auto it = lower_bound(begin(v[r]), end(v[r]), y);
        if (it != end(v[r])) {
          res = min(res, *it);
        }
      }
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  tree<int> g(n);
  for (int v = 1; v < n; ++v) {
    int p;
    cin >> p;
    --p;
    g.add(v, p);
  }
  g.build_hld();
  int m;
  cin >> m;
  vector<int> a(m), b(m);
  lazy_segtree<mini<int>, chmin> seg(n);
  seg_t se(n);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
    g.run(a[i], b[i], [&](int l, int r) {
      tie(l, r) = minmax({l, r});
      seg.act(l, r, {g.dep[g.lca(a[i], b[i])]});
    });
    if (g.in[a[i]] > g.in[b[i]]) {
      swap(a[i], b[i]);
    }
    se.add(g.in[a[i]], g.in[b[i]]);
  }
  se.build();
  vector dp(__lg(2 * n - 1), vector(n, -1));
  for (int v = 0; v < n; ++v) {
    int d = min(seg.get(g.in[v]).v, g.dep[v]);
    dp[0][v] = g.la(v, d);
  }
  for (int k = 1; k < (int)size(dp); ++k) {
    for (int v = 0; v < n; ++v) {
      dp[k][v] = dp[k - 1][dp[k - 1][v]];
    }
  }
  auto f = [&](int v, int to) {
    int res = 0;
    for (int k = size(dp); k--; ) {
      if (g.dep[dp[k][v]] > g.dep[to]) {
        v = dp[k][v];
        res += 1 << k;
      }
    }
    if (g.dep[dp[0][v]] > g.dep[to]) {
      return -1;
    }
    return res + 1;
  };
  auto lift = [&](int v, int i) {
    for (int k = size(dp); k--; ) {
      if (i >> k & 1) {
        v = dp[k][v];
      }
    }
    return v;
  };
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    int w = g.lca(u, v);
    if (u == w) {
      cout << f(v, u) << '\n';
    } else if (v == w) {
      cout << f(u, v) << '\n';
    } else {
      int x = f(u, w), y = f(v, w);
      if (x == -1 or y == -1) {
        cout << "-1\n";
        continue;
      }
      u = lift(u, x - 1), v = lift(v, y - 1);
      if (g.in[u] > g.in[v]) {
        swap(u, v);
      }
      int res = x + y;
      res -= se.lb(g.in[u], g.out[u], g.in[v]) < g.out[v];
      cout << res << '\n';
    }
  }
}