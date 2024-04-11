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
  cin.tie(nullptr)->sync_with_stdio(false);
  using ll = long long;
  int n;
  cin >> n;
  vector g(n, vector<int>(n));
  ll mn = inf<ll>;
  int mi, mj;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      cin >> g[i][j];
      g[j][i] = g[i][j];
      if (chmin(mn, g[i][j])) {
        mi = i, mj = j;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      g[i][j] -= mn;
    }
  }
  vector res(n, inf<ll>);
  for (int s : {mi, mj}) {
    vector d(n, inf<ll>);
    vector<bool> b(n);
    d[s] = 0;
    while (true) {
      int i = -1;
      for (int j = 0; j < n; ++j) {
        if (b[j]) continue;
        if (i == -1 or d[j] < d[i]) {
          i = j;
        }
      }
      if (i == -1) break;
      b[i] = true;
      for (int j = 0; j < n; ++j) {
        chmin(d[j], d[i] + g[i][j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      chmin(res[i], d[i]);
    }
  }
  for (int s : {mi, mj}) {
    vector d(n, inf<ll>);
    vector<bool> b(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        chmin(d[j], 2 * g[i][j]);
      }
    }
    while (true) {
      int i = -1;
      for (int j = 0; j < n; ++j) {
        if (b[j]) continue;
        if (i == -1 or d[j] < d[i]) {
          i = j;
        }
      }
      if (i == -1) break;
      b[i] = true;
      for (int j = 0; j < n; ++j) {
        chmin(d[j], d[i] + g[i][j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      chmin(res[i], d[i]);
    }
  }
  for (auto e : res) {
    cout << mn * (n - 1) + e << '\n';
  }
}