#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    auto res = inf<int>;
    for (int _ = 2; _--; ) {
      vector<int> cum(n + k);
      for (int i = n; i--; ) {
        cum[i] = (s[i] == '1') + cum[i + 1];
      }
      vector dp(n + k, inf<int>);
      fill(begin(dp) + n, end(dp), 0);
      for (int i = n; i--; ) {
        dp[i] = (s[i] == '0') + (cum[i + 1] - cum[i + k]) + dp[i + k];
        dp[i] = min(dp[i], (s[i] == '0') + (cum[i + 1] - cum[n]));
      }
      int t = 0;
      for (int i = 0; i <= n; ++i) {
        res = min(res, t + dp[i]);
        t += s[i] == '1';
      }
      reverse(begin(s), end(s));
    }
    cout << res << '\n';
  }
}