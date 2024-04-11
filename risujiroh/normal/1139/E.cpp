#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class T> struct Dinic {
  struct Edge { int to, rev; T cap; };
  const T inf = numeric_limits<T>::max();
  const int n;
  VV<Edge> g;
  V<> dist, i;
  Dinic(int n) : n(n), g(n), dist(n), i(n) {}
  void add_edge(int from, int to, T cap) {
    assert(from != to);
    assert(cap >= 0);
    if (!cap) return;
    g[from].emplace_back(Edge{to, (int) g[to].size(), cap});
    g[to].emplace_back(Edge{from, (int) g[from].size() - 1, 0});
  }
  void bfs(int s) {
    fill(begin(dist), end(dist), -1);
    queue<int> que;
    dist[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front(); que.pop();
      for (const auto& e : g[v]) {
        if (dist[e.to] != -1 or !e.cap) continue;
        dist[e.to] = dist[v] + 1;
        que.push(e.to);
      }
    }
  }
  T dfs(int v, int s, T f) {
    if (v == s) return f;
    for (; i[v] < (int) g[v].size(); ++i[v]) {
      Edge& e = g[v][i[v]];
      if (dist[e.to] >= dist[v] or !g[e.to][e.rev].cap) continue;
      T d = dfs(e.to, s, min(f, g[e.to][e.rev].cap));
      if (d > 0) {
        g[e.to][e.rev].cap -= d;
        e.cap += d;
        return d;
      }
    }
    return 0;
  }
  T res = 0;
  T max_flow(int s, int t) {
    assert(s != t);
    while (true) {
      bfs(s);
      if (dist[t] == -1) return res;
      fill(begin(i), end(i), 0);
      while (true) {
        T f = dfs(t, s, inf);
        if (!f) break;
        res += f;
      }
    }
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> p(n); for (auto&& e : p) cin >> e;
  V<> c(n); for (auto&& e : c) cin >> e, --e;
  int d; cin >> d;
  V<> a(n);
  for (int i = 0; i < d; ++i) {
    int k; cin >> k, --k;
    a[k] = d - i;
  }
  V<> idx(n);
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j) { return a[i] < a[j]; });
  Dinic<int> g(5000 + m + 2);
  int S = 5000 + m, T = S + 1;
  for (int i = 0; i < m; ++i) {
    g.add_edge(5000 + i, T, 1);
  }
  int x = 0;
  V<> res;
  for (int i : idx) {
    if (a[i]) {
      while (g.max_flow(S, T) == x) {
        g.add_edge(S, x++, 1);
      }
      res.push_back(x - 1);
    }
    g.add_edge(p[i], 5000 + c[i], 1);
  }
  reverse(begin(res), end(res));
  for (int e : res) { 
    cout << e << '\n';
  }
}