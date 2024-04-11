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
    int n, x;
    cin >> n >> x;
    vector<int> cnt(n + 2);
    for (int _ = n; _--; ) {
      int a;
      cin >> a;
      int m = (x + a - 1) / a;
      if (m > n) continue;
      ++cnt[m];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      int q = cnt[i] / i;
      res += q;
      cnt[i] -= q * i;
      cnt[i + 1] += cnt[i];
    }
    cout << res << '\n';
  }
}