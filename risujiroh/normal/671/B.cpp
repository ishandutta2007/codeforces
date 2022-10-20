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
  sort(begin(a), end(a));
  auto s = accumulate(begin(a), end(a), 0LL);
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    b[i] = s / n + (i >= n - s % n);
  }
  int mn, mx;
  {
    auto chk = [&](int m) {
      long long need = 0;
      for (int i = 0; i < n; ++i) {
        if (a[i] >= m) break;
        need += m - a[i];
      }
      return need <= k;
    };
    int ok = a[0], ng = b[0] + 1;
    while (ng - ok > 1) {
      int mid = (ok + ng) / 2;
      (chk(mid) ? ok : ng) = mid;
    }
    mn = ok;
  }
  {
    auto chk = [&](int m) {
      long long need = 0;
      for (int i = n; i--; ) {
        if (a[i] <= m) break;
        need += a[i] - m;
      }
      return need <= k;
    };
    int ng = b.back() - 1, ok = a.back();
    while (ok - ng > 1) {
      int mid = (ng + ok) / 2;
      (chk(mid) ? ok : ng) = mid;
    }
    mx = ok;
  }
  cout << mx - mn << '\n';
}