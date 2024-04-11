#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, c; cin >> n >> c;
  V<> a(n - 1); for (auto&& e : a) cin >> e;
  V<> b(n - 1); for (auto&& e : b) cin >> e;
  cout << 0;
  VV<> dp(2, V<>(n));
  dp[1][0] = c;
  for (int i = 1; i < n; ++i) {
    dp[0][i] = min(dp[0][i - 1] + a[i - 1], dp[1][i - 1] + b[i - 1]);
    dp[1][i] = min(dp[1][i - 1] + b[i - 1], dp[0][i] + c);
    cout << ' ' << dp[0][i];
  }
  cout << '\n';
}