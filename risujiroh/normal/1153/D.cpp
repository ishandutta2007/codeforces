#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (auto&& e : a) cin >> e;
  VV<> g(n);
  for (int i = 1; i < n; ++i) {
    int p; cin >> p, --p;
    g[p].push_back(i);
  }
  V<> c(n);
  for (int v = 0; v < n; ++v) if (!a[v] and !g[v].empty()) {
    c[v] = g[v].size() - 1;
  }
  auto dfs = [&](const auto& dfs, int v) -> int {
    if (g[v].empty()) return 1;
    if (a[v]) {
      int res = 1e9;
      for (int w : g[v]) {
        res = min(res, dfs(dfs, w));
      }
      return res;
    } else {
      int res = 0;
      for (int w : g[v]) {
        res += dfs(dfs, w);
      }
      return res;
    }
  };
  int k = 0;
  for (int v = 0; v < n; ++v) k += g[v].empty();
  int res = k + 1 - dfs(dfs, 0);
  cout << res << '\n';
}