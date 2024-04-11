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
  int n, k;
  cin >> n >> k;
  auto chk = [&](int m) {
    int rest = n - m - 1;
    int len = m / 2;
    return 2 + (rest + len - 1) / len <= k;
  };
  int ng = 1, ok = n - 1;
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
  int l = ok / 2, r = ok - l;
  vector<pair<int, int>> res;
  for (int i = 0; i < r; ++i) {
    res.emplace_back(i, i + 1);
  }
  --k;
  for (int i = r + 1; i < n; ++i) {
    if (i <= r + k) {
      res.emplace_back(r, i);
    } else {
      res.emplace_back(i - k, i);
    }
  }
  for (auto [u, v] : res) {
    cout << u + 1 << ' ' << v + 1 << '\n';
  }
}