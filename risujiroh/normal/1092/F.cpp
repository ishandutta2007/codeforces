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
  V<lint> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  V<> size(n, 1), dep(n);
  V<lint> sa(n);
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    sa[v] = a[v];
    for (int w : g[v]) if (w != p) {
      dep[w] = dep[v] + 1;
      dfs(dfs, w, v);
      size[v] += size[w];
      sa[v] += sa[w];
    }
  };
  dfs(dfs, 0, -1);
  lint suma = accumulate(begin(a), end(a), 0LL);
  V<lint> res(n);
  auto dfs2 = [&](const auto& dfs2, int v, int p) -> void {
    for (int w : g[v]) if (w != p) {
      res[w] = res[v] + suma - 2 * sa[w];
      dfs2(dfs2, w, v);
    }
  };
  for (int v = 0; v < n; ++v) res[0] += a[v] * dep[v];
  dfs2(dfs2, 0, -1);
  cout << *max_element(begin(res), end(res)) << '\n';
}