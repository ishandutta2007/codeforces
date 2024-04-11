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
  constexpr int lim = 1e6;
  vector<int> f(lim + 1);
  for (int i = 1; i <= lim; ++i) {
    if (i % 10) {
      f[i] = f[i - 1] + 1;
    } else {
      f[i] = f[i / 10];
    }
  }
  vector res(11, vector(151, inf<int>));
  for (int k = 1; k <= 10; ++k) {
    for (int i = 0; i + k - 1 <= lim; ++i) {
      int s = accumulate(begin(f) + i, begin(f) + (i + k), 0);
      if (s > 150) continue;
      chmin(res[k][s], i);
    }
    DEBUG(k, res[k]);
  }
  auto g = [](int n) {
    string s;
    if (n % 9) {
      s += '0' + n % 9;
    }
    s += string(n / 9, '9');
    return s;
  };
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    ++k;
    if (res[k][n] != inf<int>) {
      cout << res[k][n] << '\n';
    } else if (k >= 3 or (k == 2 and n < 10)) {
      cout << "-1\n";
    } else if (k == 1) {
      cout << g(n) << '\n';
    } else {
      if (n & 1) {
        auto x = stoll(g((n + 1) / 2));
        cout << x - 1 << '\n';
      } else {
        auto x = stoll(g((n - 8) / 2));
        cout << 10 * x - 1 << '\n';
      }
    }
  }
}