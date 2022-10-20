#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int f(int n) {
  if (n < 10) {
    return n;
  }
  int p = 1;
  while (n) {
    int r = n % 10;
    if (r) {
      p *= r;
    }
    n /= 10;
  }
  return f(p);
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int q;
  cin >> q;
  constexpr int lim = 1e6;
  vector cnt(10, vector(lim + 2, 0));
  for (int n = 1; n <= lim; ++n) {
    ++cnt[f(n)][n];
  }
  for (int k = 1; k < 10; ++k) {
    for (int n = lim; n; --n) {
      cnt[k][n] += cnt[k][n + 1];
    }
  }
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    int res = cnt[k][l] - cnt[k][r + 1];
    cout << res << '\n';
  }
}