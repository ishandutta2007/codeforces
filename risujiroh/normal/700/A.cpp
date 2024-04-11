#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(20);
  int n, k;
  double l, v1, v2;
  cin >> n >> l >> v1 >> v2 >> k;
  int m = (n + k - 1) / k;
  if (m == 1) {
    cout << l / v2 << '\n';
    exit(0);
  }
  auto chk = [&](double t) {
    double x = v2 * (l - v1 * t) / (v2 - v1);
    return (m * x + max(m * x - l, 0.0)) / v2 <= t;
  };
  double ng = l / v2, ok = l / v1;
  for (int _ = 100; _--; ) {
    double mid = (ng + ok) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}