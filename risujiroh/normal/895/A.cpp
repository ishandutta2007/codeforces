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
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    a[i + 1] = a[i] + x;
  }
  int res = 360;
  for (int r = 0; r <= n; ++r) {
    for (int l = 0; l <= r; ++l) {
      int d = a[r] - a[l];
      d = min(d, 360 - d);
      res = min(res, 360 - 2 * d);
    }
  }
  cout << res << '\n';
}