#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


void dfs(int v, int p, const VV<>& g, VV<>& d, V<>& res, V<>& a) {
  if (g[v].size() == 1 and g[v][0] == p) {
    d[v] = {1};
    return;
  }
  for (int w : g[v]) if (w != p) {
    dfs(w, v, g, d, res, a);
  }
  int wm = *max_element(begin(g[v]), end(g[v]), [&](int x, int y) { return d[x].size() < d[y].size(); });
  swap(d[v], d[wm]); d[wm].shrink_to_fit();
  d[v].push_back(1);
  bool c = false;
  for (int w : g[v]) if (w != p and w != wm) {
    for (int i = 0; i < d[w].size(); ++i) {
      d[v][i - d[w].size() + d[v].size() - 1] += d[w][i];
    }
    d[w].clear(); d[w].shrink_to_fit();
    c = true;
  }
  if (c) {
    res[v] = distance(rbegin(d[v]), max_element(rbegin(d[v]), rend(d[v])));
    a[v] = *max_element(rbegin(d[v]), rend(d[v]));
  } else {
    res[v] = a[wm] > 1 ? res[wm] + 1 : 0;
    a[v] = a[wm];
  }
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  if (n == 1) return cout << 0 << '\n', 0;
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y; cin >> x >> y, --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  VV<> d(n);
  V<> res(n), a(n);
  dfs(0, -1, g, d, res, a);
  for (int i = 0; i < n; ++i) cout << res[i] << '\n';
}