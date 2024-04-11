#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> t(n);
  for (auto&& e : t) cin >> e;
  vector dp(n + 1, inf<int>);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    chmin(dp[i + 1], dp[i] + 20);
    int j = max<int>(upper_bound(begin(t), end(t), t[i] - 90) - begin(t), 0);
    chmin(dp[i + 1], dp[j] + 50);
    j = max<int>(upper_bound(begin(t), end(t), t[i] - 1440) - begin(t), 0);
    chmin(dp[i + 1], dp[j] + 120);
    cout << dp[i + 1] - dp[i] << '\n';
  }
}