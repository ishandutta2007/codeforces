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
  int n, m;
  cin >> n >> m;
  vector<int> d(m), h(m);
  for (int i = 0; i < m; ++i) {
    cin >> d[i] >> h[i];
  }
  for (int i = 1; i < m; ++i) {
    if (abs(h[i] - h[i - 1]) > abs(d[i] - d[i - 1])) {
      cout << "IMPOSSIBLE\n";
      exit(0);
    }
  }
  int res = max(h[0] + d[0] - 1, h.back() + (n - d.back()));
  for (int i = 1; i < m; ++i) {
    int w = d[i] - d[i - 1];
    w -= abs(h[i] - h[i - 1]);
    res = max(res, max(h[i], h[i - 1]) + w / 2);
  }
  cout << res << '\n';
}