#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, a, b; cin >> n >> a >> b;
  V<> c(n); for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) {
    if (c[i] == 2 or c[n - 1 - i] == 2) continue;
    if (c[i] != c[n - 1 - i]) return cout << -1 << '\n', 0;
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (c[i] != 2) continue;
    res += c[n - 1 - i] == 2 ? min(a, b) : c[n - 1 - i] == 0 ? a : b;
  }
  cout << res << '\n';
}