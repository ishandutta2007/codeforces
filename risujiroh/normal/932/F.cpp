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

// need__int128_tlong double
struct ConvexHullTrick {
  using R = long double;
  using lint = long long;
  static constexpr lint max_x = 2e6; // 
  static constexpr lint inf = numeric_limits<lint>::max();
  struct Line {
    lint a, b = 0;
    R x = 0; // 
    bool operator<(const Line& r) const {
      return a == inf or r.a == inf ? x < r.x : a < r.a;
    }
  };
  set<Line> se;
  bool need(const Line& l, const Line& m, const Line& r) const {
    return (R)m.b * (r.a - l.a) > (R)l.b * (r.a - m.a) + (R)r.b * (m.a - l.a);
  }
  void add(lint a, lint b) {
    auto itr = se.find({a});
    if (itr != end(se)) {
      if (b <= itr->b) return;
      itr = se.erase(itr);
    } else {
      itr = se.lower_bound({a});
      if (itr != begin(se) and itr != end(se) and !need(*prev(itr), {a, b}, *itr)) return;
    }
    if (itr != end(se)) {
      while (next(itr) != end(se) and !need({a, b}, *itr, *next(itr))) {
        itr = se.erase(itr);
      }
    }
    if (itr != begin(se)) {
      while (prev(itr) != begin(se) and !need(*prev(itr, 2), *prev(itr), {a, b})) {
        se.erase(prev(itr));
      }
    }
    R x = max_x;
    if (itr != end(se)) {
      x = -(R)(itr->b - b) / (itr->a - a);
    }
    itr = se.emplace_hint(itr, Line{a, b, x});
    if (itr != begin(se)) {
      auto e = *prev(itr);
      se.erase(prev(itr));
      e.x = -(R)(b - e.b) / (a - e.a);
      se.insert(e);
    }
  }
  lint max(lint x) const {
    if (se.empty()) return -9e18; // 
    auto itr = se.lower_bound({inf, inf, (R)x});
    return itr->a * x + itr->b;
  }
};

struct seg_t {
  int n;
  vector<ConvexHullTrick> t;
  seg_t(int _n) : n(_n), t(2 * n) {}
  void add(int i, long long a, long long b) {
    t[i += n].add(-a, -b);
    while (i >>= 1) {
      t[i].add(-a, -b);
    }
  }
  auto fold(int l, int r, long long x) {
    long long res = 9e18;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) res = min(res, -t[l++].max(x));
      if (r & 1) res = min(res, -t[--r].max(x));
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  for (auto&& e : a) cin >> e;
  for (auto&& e : b) cin >> e;
  tree<int> g(n);
  for (int _ = n - 1; _--; ) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  g.build_hld();
  vector<long long> res(n);
  seg_t seg(n);
  for_each(rbegin(g.vs), rend(g.vs), [&](int v) {
    if (v == 0 or size(g.g[v]) > 1) {
      res[v] = seg.fold(g.in[v], g.out[v], a[v]);
    }
    DEBUG(v, res[v]);
    seg.add(g.in[v], b[v], res[v]);
  });
  for (int v = 0; v < n; ++v) {
    cout << res[v] << " \n"[v == n - 1];
  }
}