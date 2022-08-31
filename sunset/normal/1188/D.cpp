#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  for (int b = 0; b < 60; ++b) {
    sort(a.begin(), a.end(), [&](long long x, long long y) {
      return x % (1ll << b) > y % (1ll << b);
    });
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
      pref[i + 1] = pref[i] + (a[i] >> b & 1);
    }
    vector<int> new_dp(n + 1, INF);
    for (int i = 0; i <= n; ++i) {
      if (dp[i] != INF) {
        for (int w = 0; w < 2; ++w) {
          int l1 = pref[i], l0 = i - l1;
          int r1 = pref[n] - pref[i], r0 = n - i - r1;
          int to = l1 + (l0 + r1) * !w;
          int cost = (l1 + r0) * w + (l0 + r1) * !w;
          new_dp[to] = min(new_dp[to], dp[i] + cost);
        }
      }
    }
    swap(dp, new_dp);
  }
  cout << dp[0] << "\n";
  return 0;
}