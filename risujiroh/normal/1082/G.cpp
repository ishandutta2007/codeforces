#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


using Int = lint;
constexpr Int inf = 1e18;
struct Edge { int to; Int cap; size_t rev; };

void add_edge(int from, int to, Int cap, VV<Edge>& g) {
  g[from].push_back({to, cap, g[to].size()});
  g[to].push_back({from, 0, g[from].size() - 1});
}

Int dinic(int s, int t, VV<Edge>& g) {
  int n = g.size();
  V<> dist, i;

  auto bfs = [&]() -> void {
    dist.assign(n, -1);
    queue<int> q;
    dist[s] = 0; q.push(s);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      for (auto&& e : g[v]) if (dist[e.to] == -1 and e.cap > 0) {
        dist[e.to] = dist[v] + 1; q.push(e.to);
      }
    }
  };

  auto dfs = [&](const auto& dfs, int v, Int f) -> Int {
    if (v == s) return f;
    for (; i[v] < g[v].size(); i[v]++) {
      Edge& e = g[v][i[v]];
      if (dist[e.to] < dist[v] and g[e.to][e.rev].cap > 0) {
        Int d = dfs(dfs, e.to, min(f, g[e.to][e.rev].cap));
        if (d > 0) {
          g[e.to][e.rev].cap -= d;
          e.cap += d;
          return d;
        }
      }
    }
    return 0;
  };

  Int res = 0;
  while (true) {
    bfs();
    if (dist[t] == -1) return res;
    i.assign(n, 0);
    while (true) {
      Int f = dfs(dfs, t, inf);
      if (f == 0) break;
      res += f;
    }
  }
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<Edge> g(n + m + 2);
  int s = n + m, t = n + m + 1;
  for (int i = 0; i < n; ++i) {
    int a; cin >> a;
    add_edge(s, i, 0, g);
    add_edge(i, t, a, g);
  }
  lint res = 0;
  for (int i = 0; i < m; ++i) {
    int u, v, w; cin >> u >> v >> w, --u, --v;
    res += w;
    add_edge(s, n + i, w, g);
    add_edge(n + i, t, 0, g);
    add_edge(n + i, u, inf, g);
    add_edge(n + i, v, inf, g);
  }
  res -= dinic(s, t, g);
  cout << res << '\n';
}