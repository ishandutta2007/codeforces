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
  double s; cin >> s;
  VV<> g(n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v, --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int k = 0;
  for (int v = 0; v < n; ++v) {
    if (g[v].size() == 1) ++k;
  }
  cout << fixed << setprecision(15) << s / k * 2 << '\n';
}