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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int i, int j) {
      return b[i] < b[j];
    });
    vector dp(n + 1, vector(k + 1, -inf<int>));
    vector prv(n + 1, vector(k + 1, -1));
    dp[0][0] = 0;
    for (int t = 0; t < n; ++t) {
      int i = ord[t];
      for (int x = 0; x <= k; ++x) {
        if (chmax(dp[t + 1][x], dp[t][x])) {
          prv[t + 1][x] = x;
        }
        if (x == k) continue;
        if (chmax(dp[t + 1][x + 1], dp[t][x] + a[i] - (k - 1 - x) * b[i])) {
          prv[t + 1][x + 1] = x;
        }
      }
    }
    vector<int> idx, ex;
    for (int t = n, x = k; t--; ) {
      if (x != prv[t + 1][x]) {
        idx.push_back(ord[t]);
        x = prv[t + 1][x];
      } else {
        ex.push_back(ord[t]);
      }
    }
    reverse(begin(idx), end(idx));
    int last = idx.back();
    idx.pop_back();
    cout << 2 * n - k << '\n';
    for (int i : idx) {
      cout << i + 1 << ' ';
    }
    for (int i : ex) {
      cout << i + 1 << ' ' << -(i + 1) << ' ';
    }
    cout << last + 1 << '\n';
  }
}