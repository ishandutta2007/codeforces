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
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (auto&& e : a) cin >> e;
    vector<int> idx(2 * n);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](int i, int j) {
      return (a[i] & 1) < (a[j] & 1);
    });
    int cnt = 0;
    for (int t = 0; t < 2 * n; t += 2) {
      int i = idx[t], j = idx[t + 1];
      if ((a[i] & 1) != (a[j] & 1)) continue;
      cout << i + 1 << ' ' << j + 1 << '\n';
      if (++cnt == n - 1) break;
    }
  }
}