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
  int n, k;
  cin >> n >> k;
  vector dp(k, -inf<long long>);
  dp[0] = 0;
  auto sum = 0LL;
  while (n--) {
    int a, b;
    cin >> a >> b;
    vector ndp(k, -inf<long long>);
    for (int ra = 0; ra < k; ++ra) {
      int rb = (sum + k - ra) % k;
      for (int x = 0; x < k; ++x) {
        int y = x ? k - x : 0;
        if (a < x or b < y) continue;
        auto cur = dp[ra] + !!x;
        int qa = (a - x) / k;
        int qb = (b - y) / k;
        cur += qa + qb;
        int nr = ra + (a - x - qa * k);
        if (nr >= k) {
          ++cur;
          nr -= k;
        }
        cur += rb + (b - y - qb * k)>= k;
        chmax(ndp[nr], cur);
      }
    }
    swap(dp, ndp);
    sum += a + b;
    DEBUG(dp);
  }
  cout << *max_element(begin(dp), end(dp)) << '\n';
}