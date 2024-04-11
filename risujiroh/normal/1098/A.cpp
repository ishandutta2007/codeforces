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
  VV<> chi(n);
  for (int v = 1; v < n; ++v) {
    int p; cin >> p, --p;
    chi[p].push_back(v);
  }
  V<lint> s(n); for (int i = 0; i < n; ++i) cin >> s[i];
  V<lint> a(n);
  auto dfs = [&](const auto& dfs, int v, int p) -> void {
    if (s[v] != -1) {
      a[v] = s[v] - (p != -1 ? s[p] : 0);
    } else {
      if (chi[v].empty()) {
        a[v] = 0;
      } else {
        lint mn = 9e18;
        for (int w : chi[v]) {
          mn = min(mn, s[w]);
        }
        a[v] = mn - s[p];
      }
      s[v] = s[p] + a[v];
    }
    for (int w : chi[v]) {
      dfs(dfs, w, v);
    }
  };
  dfs(dfs, 0, -1);
  for (int v = 0; v < n; ++v) if (a[v] < 0) {
    return cout << -1 << '\n', 0;
  }
  lint res = accumulate(begin(a), end(a), 0LL);
  cout << res << '\n';
}