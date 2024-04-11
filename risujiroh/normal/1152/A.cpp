#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (auto&& e : a) cin >> e;
  V<> b(m); for (auto&& e : b) cin >> e;
  int ao = 0, bo = 0;
  for (int i = 0; i < n; ++i) ao += a[i] & 1;
  for (int i = 0; i < m; ++i) bo += b[i] & 1;
  int res = min(ao, m - bo) + min(n - ao, bo);
  cout << res << '\n';
}