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

template <class T, bool Scaling = false> struct dinic {
  struct edge {
    int to;
    T cap;
  };
  static constexpr inline T inf = numeric_limits<T>::max(), eps = 1e-10;
  int n, s, t;
  vector<edge> es;
  vector<vector<int>> g;
  T scale;
  vector<int> h, ptr;
  dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t), g(n), h(n), ptr(n) {}
  void add(int from, int to, T cap, T rev_cap = 0) {
    g[from].push_back(size(es)), es.push_back({to, cap});
    g[to].push_back(size(es)), es.push_back({from, rev_cap});
  }
  bool bfs() {
    static vector<int> que(n);
    fill(begin(h), end(h), -1);
    h[t] = 0, que[0] = t;
    for (int bg = 0, ed = 1; bg < ed; ) {
      int v = que[bg++];
      for (int id : g[v])
        if (es[id ^ 1].cap > scale and h[es[id].to] == -1) {
          h[es[id].to] = h[v] + 1, que[ed++] = es[id].to;
          if (es[id].to == s) return true;
        }
    }
    return false;
  }
  T dfs(int v, T f) {
    if (v == t) return f;
    for (int& i = ptr[v]; i >= 0; --i) {
      int id = g[v][i];
      if (es[id].cap > scale and h[v] > h[es[id].to])
        if (T df = dfs(es[id].to, min(f, es[id].cap)); df > eps)
          return es[id].cap -= df, es[id ^ 1].cap += df, df;
    }
    return 0;
  }
  T max_flow() {
    T flow = 0, max_cap = 0;
    for (auto&& e : es) max_cap = max(max_cap, e.cap);
    for (scale = Scaling ? max_cap / 2 : eps; ; scale /= 2) {
      while (bfs()) {
        for (int v = 0; v < n; ++v) ptr[v] = (int)size(g[v]) - 1;
        for (T df; (df = dfs(s, inf)) > eps; ) flow += df;
      }
      if (scale <= eps) break;
    }
    return flow;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  tree g(n);
  for (int id = 0; id < n - 1; ++id) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g.add(u, v);
  }
  g.build_hld();
  dinic<int> d(2 * n + m + 2, 2 * n + m, 2 * n + m + 1);
  for (int t = 1; t < n; ++t) {
    d.add(n + t, d.t, 1);
  }
  for (int i = n; i-- > 1; ) {
    d.add(i, 2 * i, d.inf);
    d.add(i, 2 * i + 1, d.inf);
  }
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    d.add(d.s, 2 * n + i, 1);
    g.run(x, y, [&](int l, int r) {
      tie(l, r) = minmax({l, r});
      for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) d.add(2 * n + i, l++, d.inf);
        if (r & 1) d.add(2 * n + i, --r, d.inf);
      }
    }, false);
  }
  cout << d.max_flow() << '\n';
  vector<int> idx, ids;
  for (int i = 0; i < m; ++i) {
    if (d.h[2 * n + i] != -1) {
      idx.push_back(i);
    }
  }
  for (int v = 1; v < n; ++v) {
    if (d.h[n + g.in[v]] == -1) {
      ids.push_back(g.pe[v]);
    }
  }
  cout << size(idx);
  for (int i : idx) {
    cout << ' ' << i + 1;
  }
  cout << '\n';
  cout << size(ids);
  for (int id : ids) {
    cout << ' ' << id + 1;
  }
  cout << '\n';
}