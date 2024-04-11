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
    int n;
    cin >> n;
    vector<long long> a(2 * n), b(2 * n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
      a[i + n] = a[i];
      b[i + n] = b[i];
    }
    vector<long long> c(2 * n + 1);
    for (int i = 2 * n; i-- > 1; ) {
      c[i] = max(a[i] - b[i - 1], 0LL) + c[i + 1];
    }
    auto res = inf<long long>;
    for (int s = 0; s < n; ++s) {
      res = min(res, a[s] + (c[s + 1] - c[s + n]));
    }
    cout << res << '\n';
  }
}