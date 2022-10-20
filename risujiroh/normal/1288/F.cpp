#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class U, class C> struct ssp {
  struct edge {
    int to;
    U cap;
    C cost;
  };
  static constexpr inline U inf = numeric_limits<U>::max(), eps = 1e-10;
  int n, s, t;
  vector<edge> es;
  vector<vector<int>> g;
  vector<C> d;
  vector<int> pe;
  ssp(int _n, int _s, int _t) : n(_n), s(_s), t(_t), g(n), d(n), pe(n) {}
  void add(int from, int to, U cap, C cost) {
    g[from].push_back(size(es)), es.push_back({to, cap, cost});
    g[to].push_back(size(es)), es.push_back({from, 0, -cost});
  }
  bool spfa() {
    static vector<bool> in(n);
    static vector<int> que;
    fill(begin(d), end(d), numeric_limits<C>::max());
    que.clear();
    d[s] = 0, in[s] = true, que.push_back(s);
    for (int bg = 0; bg < (int)size(que); ) {
      int v = que[bg++];
      in[v] = false;
      for (int id : g[v]) {
        auto&& e = es[id];
        if (e.cap > eps and d[v] + e.cost < d[e.to]) {
          d[e.to] = d[v] + e.cost, pe[e.to] = id;
          if (not in[e.to]) in[e.to] = true, que.push_back(e.to);
        }
      }
    }
    return d[t] < numeric_limits<C>::max();
  }
  pair<U, C> min_cost_max_flow() {
    U flow = 0;
    C cost = 0;
    while (spfa()) {
      U df = inf;
      for (int v = t; v != s; v = es[pe[v] ^ 1].to) df = min(df, es[pe[v]].cap);
      for (int v = t; v != s; v = es[pe[v] ^ 1].to)
        es[pe[v]].cap -= df, es[pe[v] ^ 1].cap += df;
      flow += df, cost += df * d[t];
    }
    return {flow, cost};
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int h, w, m, cr, cb;
  cin >> h >> w >> m >> cr >> cb;
  ssp<int, int> g(h + w + 3, h + w + 1, h + w + 2);
  vector<int> b(h + w + 1);
  for (int i = 0; i < h; ++i) {
    char c;
    cin >> c;
    if (c == 'R') {
      --b[h + w], ++b[i];
      g.add(h + w, i, g.inf, 0);
    } else if (c == 'B') {
      --b[i], ++b[h + w];
      g.add(i, h + w, g.inf, 0);
    } else {
      g.add(i, h + w, g.inf, 0);
      g.add(h + w, i, g.inf, 0);
    }
  }
  for (int j = 0; j < w; ++j) {
    char c;
    cin >> c;
    if (c == 'R') {
      --b[h + j], ++b[h + w];
      g.add(h + j, h + w, g.inf, 0);
    } else if (c == 'B') {
      --b[h + w], ++b[h + j];
      g.add(h + w, h + j, g.inf, 0);
    } else {
      g.add(h + j, h + w, g.inf, 0);
      g.add(h + w, h + j, g.inf, 0);
    }
  }
  int off = size(g.es);
  for (int t = 0; t < m; ++t) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    g.add(i, h + j, 1, cr);
    g.add(h + j, i, 1, cb);
  }
  int sb = 0;
  for (int v = 0; v <= h + w; ++v) {
    if (b[v] > 0) {
      g.add(g.s, v, b[v], 0);
      sb += b[v];
    } else if (b[v] < 0) {
      g.add(v, g.t, -b[v], 0);
    }
  }
  auto [f, c] = g.min_cost_max_flow();
  if (f < sb) {
    cout << "-1\n";
    exit(0);
  } else {
    cout << c << '\n';
  }
  for (int t = 0; t < m; ++t) {
    if (g.es[off + 4 * t + 1].cap) {
      cout << 'R';
    } else if (g.es[off + 4 * t + 3].cap) {
      cout << 'B';
    } else {
      cout << 'U';
    }
  }
  cout << '\n';
}