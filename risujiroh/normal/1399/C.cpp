#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n), cnt(2 * n + 1);
    for (auto&& e : a) {
      cin >> e;
      ++cnt[e];
    }
    int res = 0;
    for (int s = 2; s <= 2 * n; ++s) {
      int cur = 0;
      for (int x = 1; x <= s / 2; ++x) {
        if (2 * x == s) {
          cur += cnt[x] / 2;
        } else {
          cur += min(cnt[x], cnt[s - x]);
        }
      }
      res = max(res, cur);
    }
    cout << res << '\n';
  }
}