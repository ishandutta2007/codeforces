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
  long long n, x, k;
  cin >> n >> x >> k;
  vector<long long> a(n);
  for (auto&& e : a) {
    cin >> e;
  }
  sort(begin(a), end(a));
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    auto y = k + (a[i] + x - 1) / x;
    res += lower_bound(begin(a), end(a), x * y) - lower_bound(begin(a), end(a), max(x * (y - 1), a[i]));
  }
  cout << res << '\n';
}