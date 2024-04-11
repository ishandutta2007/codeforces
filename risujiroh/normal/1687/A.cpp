#include <bits/stdc++.h>

#ifndef LOCAL
#define LOCAL 0
#define DUMP(...) void(0)
#endif

int main() {
  using namespace std;
  cin.tie(nullptr)->sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;

    using i64 = long long;

    if (k < n) {
      vector<i64> suff(n + 1);
      for (int i = n; i--;) {
        suff[i] = a[i] + suff[i + 1];
      }
      i64 ans = 0;
      for (int i = 0; i + k <= n; ++i) {
        ans = max(ans, suff[i] - suff[i + k]);
      }
      ans += i64(k) * (k - 1) / 2;
      cout << ans << '\n';
    } else {
      i64 ans = accumulate(begin(a), end(a), 0ll);
      ans += i64(k) * n;
      ans -= n * i64(n + 1) / 2;
      cout << ans << '\n';
    }
  }
}