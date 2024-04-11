#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


constexpr lint inf = 1e18;

using T = tuple<lint, int, int>;
struct Edge { int id, to, w; };

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, m, k; cin >> n >> m >> k;
  VV<Edge> g(n);
  for (int i = 0; i < m; ++i) {
    int x, y, w; cin >> x >> y >> w, --x, --y;
    g[x].push_back({i, y, w});
    g[y].push_back({i, x, w});
  }
  V<lint> d(n, inf);
  bitset<300000> vis;
  priority_queue< T, V<T>, greater<T> > pque;
  pque.emplace(d[0] = 0, 0, -1);
  V<> res;
  while (!pque.empty()) {
    lint dv; int v, id; tie(dv, v, id) = pque.top(); pque.pop();
    if (vis[v]) continue;
    vis[v] = true;
    if (id != -1) res.push_back(id);
    for (const Edge& e : g[v]) if (d[v] + e.w < d[e.to]) {
      pque.emplace(d[e.to] = d[v] + e.w, e.to, e.id);
    }
  }
  int e = min<unsigned>(res.size(), k);
  cout << e << '\n';
  for (int i = 0; i < e; ++i) cout << res[i] + 1 << (i != e - 1 ? ' ' : '\n');
}