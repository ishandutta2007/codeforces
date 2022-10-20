#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, x; cin >> n >> x;
  V<lint> a(n); for (auto&& e : a) cin >> e;
  VV<lint> dp(3, V<lint>(n + 1));
  for (int i = 0; i < n; ++i) {
    dp[0][i + 1] = a[i] + max(dp[0][i], 0LL);
    dp[2][i + 1] = x * a[i] + max({dp[0][i], dp[2][i], 0LL});
    dp[1][i + 1] = max(dp[2][i + 1], a[i] + max({dp[1][i], dp[2][i], 0LL}));
  }
  lint res = -1e18;
  for (int i = 0; i < 3; ++i) {
    res = max(res, *max_element(begin(dp[i]), end(dp[i])));
  }
  cout << res << '\n';
}