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
  int n, m; cin >> n >> m;
  if (!m) return cout << 0 << '\n', 0;
  V<> lx(m), ly(m), ux(m), uy(m); for (int i = 0; i < m; ++i) cin >> lx[i] >> ly[i] >> ux[i] >> uy[i], --lx[i], --ly[i];
  auto vx = lx;
  vx.insert(end(vx), begin(ux), end(ux));
  sort(begin(vx), end(vx));
  vx.erase(unique(begin(vx), end(vx)), end(vx));
  auto zip_x = [&](int x) -> int { return lower_bound(begin(vx), end(vx), x) - begin(vx); };
  auto vy = ly;
  vy.insert(end(vy), begin(uy), end(uy));
  sort(begin(vy), end(vy));
  vy.erase(unique(begin(vy), end(vy)), end(vy));
  auto zip_y = [&](int y) -> int { return lower_bound(begin(vy), end(vy), y) - begin(vy); };

  int nx = vx.size() - 1, ny = vy.size() - 1;
  VV<> c(nx + 1, V<>(ny + 1));
  for (int i = 0; i < m; ++i) {
    ++c[zip_x(lx[i])][zip_y(ly[i])];
    --c[zip_x(lx[i])][zip_y(uy[i])];
    --c[zip_x(ux[i])][zip_y(ly[i])];
    ++c[zip_x(ux[i])][zip_y(uy[i])];
  }
  for (int x = 0; x <= nx; ++x) for (int y = 0; y < ny; ++y) {
    c[x][y + 1] += c[x][y];
  }
  for (int y = 0; y <= ny; ++y) for (int x = 0; x < nx; ++x) {
    c[x + 1][y] += c[x][y];
  }

  int S = nx + ny, T = S + 1;
  Dinic<int> g(T + 1);
  for (int x = 0; x < nx; ++x) {
    g.add_edge(S, x, vx[x + 1] - vx[x]);
  }
  for (int y = 0; y < ny; ++y) {
    g.add_edge(nx + y, T, vy[y + 1] - vy[y]);
  }

  for (int x = 0; x < nx; ++x) for (int y = 0; y < ny; ++y) if (c[x][y]) {
    g.add_edge(x, nx + y, g.inf);
  }

  cout << g.max_flow(S, T) << '\n';
}