#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

constexpr int inf = 1e9;
struct edge { int to, cost; edge(int to, int cost) : to(to), cost(cost) {} };

V<> bfs(int s, const VV<edge>& g) {
  V<> d(g.size(), inf);
  using P = pair<int, int>;
  deque<P> dq;
  dq.emplace_back(d[s] = 0, s);
  while (!dq.empty()) {
    int dv; int v; tie(dv, v) = dq.front(); dq.pop_front();
    if (dv > d[v]) continue;
    for (auto&& e : g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      if (e.cost) dq.emplace_back(d[e.to] = d[v] + e.cost, e.to);
      else dq.emplace_front(d[e.to] = d[v] + e.cost, e.to);
    } 
  }
  return d;
}

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  int sx, sy; cin >> sx >> sy, sx--, sy--;
  int L, R; cin >> L >> R;
  V<string> s(n); for (int i = 0; i < n; i++) cin >> s[i];
  VV<edge> g(n * m);
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m - 1; y++) {
      if (s[x][y] == '.' and s[x][y + 1] == '.') {
        g[m * x + y].emplace_back(m * x + y + 1, 1);
        g[m * x + y + 1].emplace_back(m * x + y, 1);
      }
    }
  }
  for (int y = 0; y < m; y++) {
    for (int x = 0; x < n - 1; x++) {
      if (s[x][y] == '.' and s[x + 1][y] == '.') {
        g[m * x + y].emplace_back(m * (x + 1) + y, 0);
        g[m * (x + 1) + y].emplace_back(m * x + y, 0);
      }
    }
  }
  V<> d = bfs(m * sx + sy, g);
  int res = 0;
  for (int x = 0; x < n; x++) for (int y = 0; y < m; y++) if (s[x][y] == '.') {
    int l = (d[m * x + y] - (y - sy)) / 2, r = (d[m * x + y] + y - sy) / 2;
    if (l <= L and r <= R) {
      res++;
    }
  }
  cout << res << '\n';
}