#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


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
  int mx = *max_element(begin(a), end(a));
  if (mx <= 0) {
    lint s = 0;
    int k = 0;
    for (int v = 0; v < n; ++v) if (a[v] == mx) {
      s += a[v];
      ++k;
    }
    cout << s << ' ' << k << '\n';
    return 0;
  }
  V<lint> dp(n, -1e18);
  V<> dep(n);
  VV<> chi(n);
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    dp[v] = a[v];
    for (int w : g[v]) if (w != p) {
      dep[w] = dep[v] + 1;
      chi[v].push_back(w);
      dfs(dfs, w, v);
      dp[v] += max<lint>(dp[w], 0);
    }
  };
  dep[0] = 0;
  dfs(dfs, 0, -1);
  lint dp_mx = *max_element(begin(dp), end(dp));
  int k = 0;
  V<bool> used(n);
  auto dfs2 = [&](const auto& dfs2, int v) -> bool {
    if (used[v]) return false;
    used[v] = true;
    for (int w : chi[v]) if (dp[w] > 0) {
      if (!dfs2(dfs2, w)) return false;
    }
    return true;
  };
  V<> vs(n);
  iota(begin(vs), end(vs), 0);
  sort(begin(vs), end(vs), [&](int u, int v) { return dep[u] > dep[v]; });
  for (int v : vs) if (dp[v] == dp_mx and !used[v]) {
    k += dfs2(dfs2, v);
  }
  cout << dp_mx * k << ' ' << k << '\n';
}