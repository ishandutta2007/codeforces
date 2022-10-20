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
  V<> par(n);
  VV<> chi(n);
  par[0] = -1;
  for (int v = 1; v < n; ++v) {
    cin >> par[v], --par[v];
    chi[par[v]].push_back(v);
  }
  V<> k(n);
  auto dfs = [&](auto dfs, int v) -> void {
    if (chi[v].size()) {
      for (int w : chi[v]) {
        dfs(dfs, w);
        k[v] += k[w];
      }
    } else k[v] = 1;
  };
  dfs(dfs, 0);
  sort(begin(k), end(k));
  for (int i = 0; i < n; ++i) cout << k[i] << (i != n - 1 ? ' ' : '\n');
}