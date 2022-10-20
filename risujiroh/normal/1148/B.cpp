#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  lint ta, tb; cin >> ta >> tb;
  int k; cin >> k;
  V<lint> a(n); for (auto&& e : a) cin >> e;
  V<lint> b(m); for (auto&& e : b) cin >> e;
  if (n <= k or m <= k) return cout << -1 << '\n', 0;
  lint res = 0;
  for (int i = 0; i <= k; ++i) {
    int j = lower_bound(begin(b), end(b), a[i] + ta) - begin(b);
    if (j + k - i >= m) return cout << -1 << '\n', 0;
    res = max(res, b[j + k - i]);
  }
  res += tb;
  cout << res << '\n';
}