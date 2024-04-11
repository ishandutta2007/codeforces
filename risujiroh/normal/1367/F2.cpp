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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    auto v = a;
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    int m = size(v);
    vector<vector<int>> idx(m);
    for (int i = 0; i < n; ++i) {
      int x = lower_bound(begin(v), end(v), a[i]) - begin(v);
      idx[x].push_back(i);
    }
    DEBUG(idx);
    vector<int> x(m), y(m);
    int res = 0;
    for (int j = 0; j < m; ++j) {
      if (j + 1 < m) {
        x[j] = count_if(begin(idx[j]), end(idx[j]), [&](int e) { return e < idx[j + 1][0]; });
      }
      if (j) {
        y[j] = count_if(begin(idx[j]), end(idx[j]), [&](int e) { return e > idx[j - 1].back(); });
      }
      res = max(res, (int)size(idx[j]));
    }
    for (int j = 1; j < m; ++j) {
      for (int k = 0; k < (int)size(idx[j - 1]); ++k) {
        int cnt = end(idx[j]) - upper_bound(begin(idx[j]), end(idx[j]), idx[j - 1][k]);
        res = max(res, k + 1 + cnt);
      }
    }
    int mx = 0;
    for (int j = 0; j < m; ++j) {
      res = max(res, mx + y[j]);
      int nmx = x[j];
      if (j) {
        nmx = max(nmx, x[j - 1] + (int)size(idx[j]));
        if (idx[j - 1].back() < idx[j][0]) {
          nmx = max(nmx, mx + (int)size(idx[j]));
        }
      }
      mx = nmx;
    }
    res = n - res;
    cout << res << '\n';
  }
}