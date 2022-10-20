#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  V<> res(1 << 21);
  V<> dp(21);
  for (int k = 0; k <= 20; ++k) {
    if (k) {
      dp[k] = 2 * dp[k - 1];
      dp[k] += ~k & 1;
    }
    res[~(~0U << k) + dp[k]] = 1;
    res[~(~0U << k) + dp[k] + 1] = 1;
  }

  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  cout << res[n] << '\n';
}