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
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  auto chk = [&](int m) {
    for (int p = 0; p < 2; ++p) {
      int len = 0;
      for (auto e : a) {
        if ((len & 1) == p and e > m) continue;
        ++len;
      }
      if (len >= k) {
        return true;
      }
    }
    return false;
  };
  int ng = 0, ok = 1e9;
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    (chk(mid) ? ok : ng) = mid;
  }
  cout << ok << '\n';
}