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
  int tt = 1;
  // cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<int> x, y, z;
    while (n--) {
      int t, a, b;
      cin >> t >> a >> b;
      if (a and b) {
        z.push_back(t);
      } else if (a) {
        x.push_back(t);
      } else if (b) {
        y.push_back(t);
      }
    }
    int nx = size(x);
    int ny = size(y);
    int nz = size(z);
    if (nz + min(nx, ny) < k) {
      cout << "-1\n";
      continue;
    }
    sort(begin(x), end(x));
    sort(begin(y), end(y));
    sort(begin(z), end(z));
    partial_sum(begin(x), end(x), begin(x));
    partial_sum(begin(y), end(y), begin(y));
    partial_sum(begin(z), end(z), begin(z));
    x.insert(begin(x), 0);
    y.insert(begin(y), 0);
    z.insert(begin(z), 0);
    int res = numeric_limits<int>::max();
    for (int i = 0; i <= min(k, nz); ++i) {
      int j = k - i;
      if (j < 0 or j > min(nx, ny)) continue;
      res = min(res, z[i] + x[j] + y[j]);
    }
    cout << res << '\n';
  }
}