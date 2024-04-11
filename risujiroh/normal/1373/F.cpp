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
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto&& e : a) cin >> e;
    for (auto&& e : b) cin >> e;
    vector dp(4, vector(4, inf<long long>));
    for (int x = 1; x < 4; ++x) {
      dp[x][x] = 0;
      if (x & 1) {
        dp[x][x] += b[0];
      }
      if (x & 2) {
        dp[x][x] += a[0];
      }
    }
    for (int i = 1; i < n; ++i) {
      for (auto&& e : dp) {
        vector ndp(4, inf<long long>);
        for (int x = 1; x < 4; ++x) {
          for (int y = 1; y < 4; ++y) {
            if (~x >> 0 & 1 and ~y >> 1 & 1) continue;
            int cur = 0;
            if (y & 1) {
              cur += b[i];
            }
            if (y & 2) {
              cur += a[i];
            }
            chmin(ndp[y], e[x] + cur);
          }
        }
        swap(e, ndp);
      }
    }
    auto mn = inf<long long>;
    for (int x = 1; x < 4; ++x) {
      for (int y = 1; y < 4; ++y) {
        if (~x >> 1 & 1 and ~y >> 0 & 1) continue;
        chmin(mn, dp[x][y]);
      }
    }
    if (mn < accumulate(begin(a), end(a), 0LL)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}