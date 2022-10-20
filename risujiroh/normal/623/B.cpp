#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> map<T, int> factorize(T n) {
  map<T, int> res;
  for (T i = 2; i * i <= n; ++i)
    while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

auto chmin = [](auto&& a, auto b) { return b < a ? a = b, 1 : 0; };

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  using ll = long long;
  ll c, d;
  cin >> c >> d;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  ll res = numeric_limits<ll>::max();
  for (int _ = 2; _--; ) {
    for (int delta = -1; delta <= +1; ++delta) {
      for (auto [p, e] : factorize(a[0] + delta)) {
        vector dp(3, inf<ll>);
        dp[0] = delta ? d : 0;
        for (int i = 1; i < n; ++i) {
          vector ndp(3, inf<ll>);
          int r = a[i] % p;
          if (r == 0) {
            chmin(ndp[0], dp[0]);
            chmin(ndp[2], dp[1]);
            chmin(ndp[1], dp[1] + c);
            chmin(ndp[2], dp[2]);
          } else if (r == 1 or r == p - 1) {
            chmin(ndp[0], dp[0] + d);
            chmin(ndp[1], dp[0] + c);
            chmin(ndp[2], dp[1] + d);
            chmin(ndp[1], dp[1] + c);
            chmin(ndp[2], dp[2] + d);
          } else {
            chmin(ndp[1], dp[0] + c);
            chmin(ndp[1], dp[1] + c);
          }
          swap(dp, ndp);
        }
        chmin(res, *min_element(begin(dp), end(dp)));
      }
    }
    reverse(begin(a), end(a));
  }
  cout << res << '\n';
}