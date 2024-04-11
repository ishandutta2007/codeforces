#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

auto f(vector<int> a) {
  auto res = 0LL, mn = 0LL, t = 0LL;
  for (int e : a) {
    t += e;
    res = max(res, t - mn);
    mn = min(mn, t);
  }
  return res;
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  vector<int> b(n - 1), c(n - 2);
  for (int i = 0; i < n - 1; ++i) {
    b[i] = abs(a[i] - a[i + 1]);
    if (i & 1) {
      b[i] = -b[i];
    }
  }
  for (int i = 0; i < n - 2; ++i) {
    c[i] = abs(a[i + 1] - a[i + 2]);
    if (i & 1) {
      c[i] = -c[i];
    }
  }
  cout << max(f(b), f(c)) << '\n';
}