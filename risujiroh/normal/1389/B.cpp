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
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> a(n);
    for (auto&& e : a) cin >> e;
    int res = 0;
    for (int x = 0; x <= z and 2 * x <= k; ++x) {
      int m = k + 1 - 2 * x;
      int cur = accumulate(begin(a), begin(a) + m, 0), mx = 0;
      if (x) {
        for (int i = 0; i < m; ++i) {
          mx = max(mx, a[i] + a[i + 1]);
        }
      }
      cur += mx * x;
      res = max(res, cur);
    }
    cout << res << '\n';
  }
}