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
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    while (n--) {
      int a;
      cin >> a;
      ++mp[(k - a % k) % k];
    }
    long long res = 0;
    for (auto [r, c] : mp) {
      if (r == 0) continue;
      res = max(res, (c - 1LL) * k + r + 1);
    }
    cout << res << '\n';
  }
}