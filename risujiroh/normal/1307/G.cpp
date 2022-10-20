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
  vector<pair<U, C>> min_cost_max_flow() {
    U flow = 0;
    C cost = 0;
    vector<pair<U, C>> res;
    while (spfa()) {
      U df = inf;
      for (int v = t; v != s; v = es[pe[v] ^ 1].to) df = min(df, es[pe[v]].cap);
      for (int v = t; v != s; v = es[pe[v] ^ 1].to)
        es[pe[v]].cap -= df, es[pe[v] ^ 1].cap += df;
      flow += df, cost += df * d[t];
      res.emplace_back(flow, cost);
    }
    return res;
  }
};

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, m;
  cin >> n >> m;
  ssp<int, int> g(n, 0, n - 1);
  while (m--) {
    int v, w, c;
    cin >> v >> w >> c;
    --v, --w;
    g.add(v, w, 1, c);
  }
  auto points = g.min_cost_max_flow();
  constexpr int lim = 1e5;
  vector<double> res(lim + 1);
  auto it = begin(points);
  for (int i = 0; i <= lim; ++i) {
    auto eval = [&](auto p) {
      double x, y;
      tie(x, y) = p;
      return (y + i) / x;
    };
    while (next(it) != end(points) and eval(*it) > eval(*next(it))) {
      ++it;
    }
    res[i] = eval(*it);
  }
  int q;
  cin >> q;
  while (q--) {
    int i;
    cin >> i;
    cout << res[i] << '\n';
  }
}