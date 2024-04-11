#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> d0(n, -1);
  auto dfs0 = [&](auto dfs0, int v) -> void {
    for (int w : g[v]) if (d0[w] == -1) {
      d0[w] = d0[v] + 1;
      dfs0(dfs0, w);
    }
  };
  d0[0] = 0;
  dfs0(dfs0, 0);
  int v0 = distance(begin(d0), max_element(begin(d0), end(d0)));
  fill(begin(d0), end(d0), -1);
  d0[v0] = 0;
  dfs0(dfs0, v0);
  int v1 = distance(begin(d0), max_element(begin(d0), end(d0)));
  if (d0[v1] & 1) return cout << "No" << '\n', 0;
  V<> d1(n, -1);
  auto dfs1 = [&](auto dfs1, int v) -> void {
    for (int w : g[v]) if (d1[w] == -1) {
      d1[w] = d1[v] + 1;
      dfs1(dfs1, w);
    }
  };
  d1[v1] = 0;
  dfs1(dfs1, v1);
  int c;
  for (int v = 0; v < n; ++v) if (d0[v] == d0[v1] / 2 and d1[v] == d1[v0] / 2) c = v;
  if (g[c].size() < 3) return cout << "No" << '\n', 0;
  V<> dc(n, -1);
  auto dfsc = [&](auto dfsc, int v) -> void {
    for (int w : g[v]) if (dc[w] == -1) {
      dc[w] = dc[v] + 1;
      dfsc(dfsc, w);
    }
  };
  dc[c] = 0;
  dfsc(dfsc, c);
  for (int v = 0; v < n; ++v) if (v != c) {
    if (dc[v] > k) return cout << "No" << '\n', 0;
    if (dc[v] == k and g[v].size() != 1) return cout << "No" << '\n', 0;
    if (dc[v] < k and g[v].size() < 4) return cout << "No" << '\n', 0;
  }
  cout << "Yes" << '\n';
}