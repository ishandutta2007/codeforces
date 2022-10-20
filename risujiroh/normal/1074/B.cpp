#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  int t; cin >> t;
  for (int it = 0; it < t; ++it) {
    int n; cin >> n;
    VV<> g(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v; cin >> u >> v, --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int k0; cin >> k0;
    V<> x(k0); for (int i = 0; i < k0; ++i) cin >> x[i], --x[i];
    sort(begin(x), end(x));
    int k1; cin >> k1;
    V<> y(k1); for (int i = 0; i < k1; ++i) cin >> y[i], --y[i];
    sort(begin(y), end(y));
    cout << "B " << y[0] + 1 << endl;
    int v1; cin >> v1, --v1;
    int res = -2;
    if (binary_search(begin(x), end(x), v1)) res = v1;
    else {
      int v0 = -1;
      auto dfs = [&](auto dfs, int v, int p) -> bool {
        if (binary_search(begin(x), end(x), v)) {
          v0 = v;
          return true;
        }
        for (int w : g[v]) if (w != p) {
          if (dfs(dfs, w, v)) return true;
        }
        return false;
      };
      dfs(dfs, v1, -1);
      cout << "A " << v0 + 1 << endl;
      int v2; cin >> v2, --v2;
      if (binary_search(begin(y), end(y), v2)) res = v0;
    }
    cout << "C " << res + 1 << endl;
  }
}