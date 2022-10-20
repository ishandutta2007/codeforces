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
  string a;
  cin >> a;
  reverse(begin(a), end(a));
  int n;
  cin >> n;
  int m = 1024;
  vector<string> s(n);
  vector<int> len;
  for (auto&& e : s) {
    cin >> e;
    len.push_back(size(e));
    reverse(begin(e), end(e));
    e += string(m - size(e), '0');
  }
  vector<int> c(10);
  for (auto&& e : c) cin >> e;
  vector<int> rnk(n);
  iota(begin(rnk), end(rnk), 0);
  vector dp(n + 1, -inf<int>);
  dp[n] = 0;
  for (int j = 0; j < m; ++j) {
    vector<int> ord(n);
    for (int i = 0; i < n; ++i) {
      ord[rnk[i]] = i;
    }
    vector ndp(n + 1, -inf<int>);
    for (int d = 0; d < 10; ++d) {
      if (j < (int)size(a)) {
        if (a[j] != '?' and (a[j] - '0') != d) continue;
        if (j == (int)size(a) - 1 and d == 0) continue;
      } else {
        if (d) continue;
      }
      int cost = 0, nx = 0;
      for (int i = 0; i < n; ++i) {
        int t = (rnk[i] >= 0) + (s[i][j] - '0') + d;
        if (t or j < max(len[i], (int)size(a))) {
          cost += c[t % 10];
        }
        nx += t < 10;
      }
      for (int x = 0; x <= n; ++x) {
        if (x) {
          int i = ord[x - 1];
          {
            int t = 1 + (s[i][j] - '0') + d;
            if (t or j < max(len[i], (int)size(a))) {
              cost -= c[t % 10];
            }
            nx -= t < 10;
          }
          {
            int t = 0 + (s[i][j] - '0') + d;
            if (t or j < max(len[i], (int)size(a))) {
              cost += c[t % 10];
            }
            nx += t < 10;
          }
        }
        // int cost = 0, nx = 0;
        // for (int i = 0; i < n; ++i) {
        //   int t = (rnk[i] >= x) + (s[i][j] - '0') + d;
        //   if (t or j < len[i]) {
        //     cost += c[t % 10];
        //   }
        //   nx += t < 10;
        // }
        chmax(ndp[nx], dp[x] + cost);
      }
    }
    {
      vector<array<int, 3>> v(n);
      for (int i = 0; i < n; ++i) {
        v[i] = {s[i][j] - '0', rnk[i], i};
      }
      sort(begin(v), end(v));
      for (int t = 0; t < n; ++t) {
        rnk[v[t][2]] = t;
      }
    }
    swap(dp, ndp);
  }
  cout << dp[n] << '\n';
}