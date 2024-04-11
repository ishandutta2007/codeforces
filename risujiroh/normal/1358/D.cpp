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
  long long m;
  cin >> n >> m;
  vector<long long> a(2 * n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[n + i] = a[i];
  }
  vector<long long> cum(2 * n + 1), sum(2 * n + 1);
  for (int i = 0; i < 2 * n; ++i) {
    cum[i + 1] = cum[i] + a[i];
    sum[i + 1] = sum[i] + a[i] * (a[i] + 1) / 2;
  }
  long long res = 0;
  for (int l = 0; l < n; ++l) {
    int r = upper_bound(begin(cum), end(cum), cum[l] + m) - begin(cum) - 1;
    auto x = m - (cum[r] - cum[l]);
    res = max(res, sum[r] - sum[l] + x * (x + 1) / 2);
  }
  reverse(begin(a), end(a));
  for (int i = 0; i < 2 * n; ++i) {
    cum[i + 1] = cum[i] + a[i];
    sum[i + 1] = sum[i] + a[i] * (a[i] + 1) / 2;
  }
  for (int l = 0; l < n; ++l) {
    int r = upper_bound(begin(cum), end(cum), cum[l] + m) - begin(cum) - 1;
    auto x = m - (cum[r] - cum[l]);
    res = max(res, sum[r] - sum[l] + x * (2 * a[r] - x + 1) / 2);
  }
  cout << res << '\n';
}