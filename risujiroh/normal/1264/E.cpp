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
  int n, m;
  cin >> n >> m;
  vector done(n, vector(n, false));
  int nn = n * n;
  ssp<int, int> g(nn + n + 2, nn + n, nn + n + 1);
  while (m--) {
    int i, j;
    cin >> i >> j;
    --i, --j;
    if (i < j) {
      g.add(i * n + j, nn + i, 1, 0);
      done[i][j] = true;
    } else {
      g.add(j * n + i, nn + i, 1, 0);
      done[j][i] = true;
    }
  }
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      g.add(g.s, i * n + j, 1, 0);
      if (done[i][j]) continue;
      g.add(i * n + j, nn + i, 1, 0);
      g.add(i * n + j, nn + j, 1, 0);
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int dy = 0; dy < n - 1; ++dy) {
      g.add(nn + i, g.t, 1, dy);
    }
  }
  g.min_cost_max_flow();
  vector res(n, string(n, '0'));
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < j; ++i) {
      for (int id : g.g[i * n + j]) {
        if (g.es[id].to == nn + i and g.es[id ^ 1].cap) {
          res[i][j] = '1';
        }
        if (g.es[id].to == nn + j and g.es[id ^ 1].cap) {
          res[j][i] = '1';
        }
      }
    }
  }
  for (auto e : res) {
    cout << e << '\n';
  }
}