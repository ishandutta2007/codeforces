#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> r(n), b(n);
  auto dfs0 = [&](const auto& dfs0, int v, int p) -> void {
    if (a[v] == 1) r[v] = 1;
    if (a[v] == 2) b[v] = 1;
    for (int w : g[v]) if (w != p) {
      dfs0(dfs0, w, v);
      r[v] += r[w];
      b[v] += b[w];
    }
  };
  int R = count(begin(a), end(a), 1);
  int B = count(begin(a), end(a), 2);
  dfs0(dfs0, 0, -1);
  int res = 0;
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    for (int w : g[v]) if (w != p) {
      res += (!r[w] or !b[w]) and (!(R - r[w]) or !(B - b[w]));
      dfs(dfs, w, v);
    }
  };
  dfs(dfs, 0, -1);
  cout << res << '\n';
}