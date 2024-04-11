#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr array<int, 8> ki = {-2, -2, -1, -1, +1, +1, +2, +2};
constexpr array<int, 8> kj = {-1, +1, -2, +2, -2, +2, -1, +1};
constexpr array<int, 4> bi = {+1, +1, -1, -1};
constexpr array<int, 4> bj = {+1, -1, +1, -1};
constexpr array<int, 4> ri = {+1, -1,  0,  0};
constexpr array<int, 4> rj = { 0,  0, +1, -1};

struct Edge { int to; pair<int, int> cost; };

template<class T, class Edge> V<T> dijkstra(const VV<Edge>& g, int s = 0) {
  V<T> dist(g.size(), {1e9, 1e9});
  using P = pair<T, int>;
  priority_queue<P, V<P>, greater<P> > pque;
  pque.emplace(dist[s] = {0, 0}, s);
  while (!pque.empty()) {
    T d; int v;
    tie(d, v) = pque.top(); pque.pop();
    if (d > dist[v]) continue;
    for (const auto& e : g[v]) {
      if (dist[e.to] <= make_pair(dist[v].first + e.cost.first, dist[v].second + e.cost.second)) continue;
      pque.emplace(dist[e.to] = {dist[v].first + e.cost.first, dist[v].second + e.cost.second}, e.to);
    }
  }
  return dist;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  VV<> a; assign(a, n, n, 0);
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    cin >> a[i][j];
  }
  V<> ord(n * n + 1);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord) - 1, [&](int x, int y) { return a[x / n][x % n] < a[y / n][y % n]; });
  auto in = [&](int i, int j) -> bool {
    return 0 <= i and i < n and 0 <= j and j < n;
  };

  VV<Edge> g(3 * n * n * n * n + 1);
  auto v = [&](int x, int i, int j, int k) -> int {
    return 3 * (x * n * n + i * n + j) + k + 1;
  };
  for (int k = 0; k < 3; ++k) {
    g[0].emplace_back(Edge{v(0, ord[0] / n, ord[0] % n, k), {0, 0}});
  }
  for (int x = 0; x < n * n; ++x) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    for (int d = 0; d < 8; ++d) {
      int ni = i + ki[d], nj = j + kj[d];
      if (!in(ni, nj)) continue;
      int nx = x + (ord[x + 1] == ni * n + nj);
      g[v(x, i, j, 0)].emplace_back(Edge{v(nx, ni, nj, 0), {1, 0}});
    }
    for (int d = 0; d < 4; ++d) {
      for (int ni = i + bi[d], nj = j + bj[d]; in(ni, nj); ni += bi[d], nj += bj[d]) {
        int nx = x + (ord[x + 1] == ni * n + nj);
        g[v(x, i, j, 1)].emplace_back(Edge{v(nx, ni, nj, 1), {1, 0}});
      }
    }
    for (int d = 0; d < 4; ++d) {
      for (int ni = i + ri[d], nj = j + rj[d]; in(ni, nj); ni += ri[d], nj += rj[d]) {
        int nx = x + (ord[x + 1] == ni * n + nj);
        g[v(x, i, j, 2)].emplace_back(Edge{v(nx, ni, nj, 2), {1, 0}});
      }
    }
    for (int k = 0; k < 3; ++k) for (int l = 0; l < 3; ++l) if (k != l) {
      g[v(x, i, j, k)].emplace_back(Edge{v(x, i, j, l), {1, 1}});
    }
  }

  auto dist = dijkstra< pair<int, int>, Edge>(g);
  pair<int, int> res = {1e9, 1e9};
  for (int k = 0; k < 3; ++k) {
    res = min(res, dist[v(n * n - 1, ord[n * n - 1] / n, ord[n * n - 1] % n, k)]);
  }
  cout << res.first << ' ' << res.second << '\n';
}