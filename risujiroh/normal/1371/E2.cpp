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
  int n, p;
  cin >> n >> p;
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  sort(begin(a), end(a));
  vector<int> cnt(2 * n - 2);
  for (int i = 0, ptr = 0; i < 2 * n - 2; ++i) {
    int upper = a.back() - n + 1 + i;
    while (ptr < n and a[ptr] <= upper) {
      ++ptr;
    }
    cnt[i] = ptr;
  }
  DEBUG(cnt);
  vector<int> d(n);
  int mn = n;
  for (int i = 0; i < n; ++i) {
    d[i] = cnt[i] - i;
    if (p - d[i] <= i) {
      mn = min({mn, p - d[i]});
    }
  }
  auto min_d = *min_element(begin(d), end(d));
  DEBUG(1 - min_d, mn);
  // [1 - min_d, p - 1)
  vector<int> res;
  for (int i = 1 - min_d; i < mn; ++i) {
    res.push_back(a.back() - n + 1 + i);
  }
  int k = size(res);
  cout << k << '\n';
  for (int i = 0; i < k; ++i) {
    cout << res[i] << " \n"[i == k - 1];
  }
}