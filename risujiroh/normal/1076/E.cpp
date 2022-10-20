#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y; cin >> x >> y, --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  V<> h(n);
  auto dfs = [&](auto dfs, int v, int p) -> void {
    for (int w : g[v]) if (w != p) {
      dfs(dfs, w, v);
      h[v] = max(h[v], h[w] + 1);
    }
  };
  dfs(dfs, 0, -1);
  struct Q { int d, x; };
  VV<Q> qs(n);
  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    int v, d, x; cin >> v >> d >> x, --v;
    qs[v].push_back({min(d, h[v]), x});
  }
  V<lint> res(n);
  auto dfs1 = [&](auto dfs1, int v, int p, auto&& a, int s) -> void {
    for (const Q& q : qs[v]) {
      a[s] += q.x;
      a[s + q.d + 1] -= q.x;
    }
    a[s + 1] += res[v] = a[s];
    int wm = -1;
    for (int w : g[v]) if (w != p) {
      if (wm == -1 and h[w] + 1 == h[v]) {
        wm = w;
        continue;
      }
      dfs1(dfs1, w, v, V<lint>(next(begin(a), s + 1), next(begin(a), s + h[w] + 3)), 0);
    }
    if (wm != -1) dfs1(dfs1, wm, v, a, s + 1);
  };
  dfs1(dfs1, 0, -1, V<lint>(h[0] + 2), 0);
  for (int i = 0; i < n; ++i) cout << res[i] << (i != n - 1 ? ' ' : '\n');
}