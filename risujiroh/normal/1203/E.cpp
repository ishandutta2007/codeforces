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
    g[from].emplace_back(Edge{to, (int)g[to].size(), cap});
    g[to].emplace_back(Edge{from, (int)g[from].size() - 1, 0});
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
    for (; i[v] < (int)g[v].size(); ++i[v]) {
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
  T max_flow(int s, int t) {
    assert(s != t);
    T res = 0;
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
  int n; cin >> n;
  int S = n + 150002, T = S + 1;
  Dinic<int> g(T + 1);
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    g.add_edge(S, i, 1);
    for (int x = max(a - 1, 1); x <= a + 1; ++x) {
      g.add_edge(i, n + x, 1);
    }
  }
  for (int i = 1; i <= 150001; ++i) {
    g.add_edge(n + i, T, 1);
  }
  cout << g.max_flow(S, T) << '\n';
}