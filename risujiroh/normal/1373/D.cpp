#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmax = [](auto&& a, auto b) { return a < b ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    vector dp(4, -inf<long long>);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
      vector ndp(4, -inf<long long>);
      if (i % 2 == 0) {
        chmax(ndp[0], dp[0] + a[i]);
        chmax(ndp[2], dp[0]);
        chmax(ndp[1], dp[1]);
        chmax(ndp[2], dp[2]);
        chmax(ndp[3], dp[2] + a[i]);
        chmax(ndp[3], dp[3] + a[i]);
      } else {
        chmax(ndp[0], dp[0]);
        chmax(ndp[1], dp[0] + a[i]);
        chmax(ndp[1], dp[1] + a[i]);
        chmax(ndp[3], dp[1]);
        chmax(ndp[2], dp[2] + a[i]);
        chmax(ndp[3], dp[3]);
      }
      swap(dp, ndp);
    }
    auto res = max(dp[0], dp[3]);
    chmax(res, n & 1 ? dp[1] : dp[2]);
    cout << res << '\n';;
  }
}