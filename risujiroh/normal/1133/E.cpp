#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, k; cin >> n >> k;
  V<> a(n); for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  VV<> dp(n + 1, V<>(k + 1));
  for (int i = 0; i < n; ++i) {
    int j = lower_bound(begin(a), end(a), a[i] - 5) - begin(a);
    for (int x = 1; x <= k; ++x) {
      dp[i + 1][x] = max(dp[i][x], dp[j][x - 1] + (i + 1 - j));
    }
  }
  cout << *max_element(begin(dp[n]), end(dp[n])) << '\n';
}