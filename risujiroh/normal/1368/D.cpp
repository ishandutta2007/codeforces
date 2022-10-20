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
  cin >> n;
  vector<long long> a(n), b(n);
  for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  for (int k = 0; k < 20; ++k) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      cnt += a[i] >> k & 1;
    }
    for (int i = n - cnt; i < n; ++i) {
      b[i] += 1 << k;
    }
  }
  auto res = 0LL;
  for (auto e : b) {
    res += e * e;
  }
  cout << res << '\n';
}