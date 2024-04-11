#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n, p, k;
    cin >> n >> p >> k;
    vector<int> a(n);
    for (auto&& e : a) {
      cin >> e;
    }
    sort(begin(a), end(a));
    vector<long long> dp(n + 1);
    int res = 0;
    for (int i = 0; i < n; ++i) {
      dp[i + 1] = dp[i] + a[i];
      if (i + 1 - k >= 0) {
        dp[i + 1] = min(dp[i + 1], dp[i + 1 - k] + a[i]);
      }
      if (dp[i + 1] <= p) {
        res = max(res, i + 1);
      }
    }
    cout << res << '\n';
  }
}