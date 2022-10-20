#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<lint> x(n); for (auto&& e : x) cin >> e;
  V<lint> p(m); for (auto&& e : p) cin >> e;
  lint d = 0;
  for (int i = 0; i < n - 1; ++i) {
    d = __gcd(d, x[i + 1] - x[i]);
  }
  for (int j = 0; j < m; ++j) if (d % p[j] == 0) {
    cout << "YES" << '\n';
    cout << x[0] << ' ' << j + 1 << '\n';
    return 0;
  }
  cout << "NO" << '\n';
}