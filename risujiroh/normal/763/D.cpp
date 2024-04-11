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

template <class Node, class T> auto tree_dp(tree<T>& g, int r = 0) {
  g.build_hld(r);
  vector<Node> lower(g.n - 1), upper(g.n - 1), all(g.n);
  vector<vector<Node>> cum(g.n);
  for_each(rbegin(g.vs), rend(g.vs), [&](int v) {
    int m = size(g.g[v]) - (v != r);
    cum[v].resize(m + 1);
    for (int i = m; i--; ) cum[v][i] = lower[g.g[v][i]] + cum[v][i + 1];
    if (v != r) lower[g.pe[v]] = cum[v][0].add(v, g.pe[v]);
  });
  for (int v : g.vs) {
    Node cur = v != r ? upper[g.pe[v]] : Node();
    for (int i = 0; i < (int)size(cum[v]) - 1; ++i) {
      upper[g.g[v][i]] = (cur + cum[v][i + 1]).add(v, g.g[v][i]);
      cur = cur + lower[g.g[v][i]];
    }
    all[v] = cur.add(v);
  }
  return make_tuple(lower, upper, all);
}

template <class T, class Op = multiplies<T>>
constexpr T power(T a, long long n, Op op = Op(), T e = {1}) {
  assert(n >= 0);
  while (n) {
    if (n & 1) e = op(e, a);
    if (n >>= 1) a = op(a, a);
  }
  return e;
}

template <unsigned M> struct modular {
  using m = modular;
  static constexpr unsigned mod = M;
  unsigned v;
  modular(long long x = 0) : v((x %= mod) < 0 ? x + mod : x) {}
  m operator-() const { return m() -= *this; }
  m& operator+=(m b) { if ((int)(v += b.v - mod) < 0) v += mod; return *this; }
  m& operator-=(m b) { if ((int)(v -= b.v) < 0) v += mod; return *this; }
  m& operator*=(m b) { v = (uint64_t)v * b.v % mod; return *this; }
  m& operator/=(m b) { return *this *= power(b, mod - 2); }
  friend m operator+(m a, m b) { return a += b; }
  friend m operator-(m a, m b) { return a -= b; }
  friend m operator*(m a, m b) { return a *= b; }
  friend m operator/(m a, m b) { return a /= b; }
  friend bool operator==(m a, m b) { return a.v == b.v; }
};

using mint = modular<2 * power(10, 9) + 33>;

mt19937 mt_engine(chrono::steady_clock::now().time_since_epoch().count());
template <class T> enable_if_t<is_integral_v<T>, T> rng(T l, T r) {
  return uniform_int_distribution<T>(l, r - 1)(mt_engine);
}
template <class T> enable_if_t<is_floating_point_v<T>, T> rng(T l, T r) {
  return uniform_real_distribution<T>(l, r)(mt_engine);
}

vector<mint> rv;

struct node {
  int height = -1;
  mint hash = 1;
  friend node operator+(node a, node b) {
    a.height = max(a.height, b.height);
    a.hash *= b.hash;
    return a;
  }
  node add([[maybe_unused]] int v, [[maybe_unused]] int id = -1) const {
    auto a = *this;
    a.hash += rv[++a.height];
    return a;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  tree g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  rv.resize(n);
  generate(begin(rv), end(rv), bind(rng<int>, 0, mint::mod));
  auto [lower, upper, all] = tree_dp<node>(g);
  vector<int> val;
  for (auto e : lower) val.push_back(e.hash.v);
  for (auto e : upper) val.push_back(e.hash.v);
  for (auto e : all) val.push_back(e.hash.v);
  sort(begin(val), end(val));
  val.erase(unique(begin(val), end(val)), end(val));
  for (auto&& e : lower) e.hash.v = lower_bound(begin(val), end(val), e.hash.v) - begin(val);
  for (auto&& e : upper) e.hash.v = lower_bound(begin(val), end(val), e.hash.v) - begin(val);
  for (auto&& e : all) e.hash.v = lower_bound(begin(val), end(val), e.hash.v) - begin(val);
  vector<int> cnt(3 * n);
  int cur = 0;
  auto add = [&](auto e) {
    cur += cnt[e.hash.v]++ == 0;
  };
  auto rm = [&](auto e) {
    cur -= --cnt[e.hash.v] == 0;
  };
  add(all[0]);
  for (auto e : lower) {
    add(e);
  }
  vector<int> num(n);
  auto dfs = [&](auto&& self, int v) -> void {
    num[v] = cur;
    for (int id : g.g[v]) {
      if (id == g.pe[v]) continue;
      int to = g.es[id] - v;
      rm(all[v]);
      rm(lower[g.pe[to]]);
      add(all[to]);
      add(upper[g.pe[to]]);
      self(self, to);
      rm(upper[g.pe[to]]);
      rm(all[to]);
      add(lower[g.pe[to]]);
      add(all[v]);
    }
  };
  dfs(dfs, 0);
  cout << max_element(begin(num), end(num)) - begin(num) + 1 << '\n';
}