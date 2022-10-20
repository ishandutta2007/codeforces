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
  int n, m, k;
  cin >> n >> m >> m >> k;
  --k;
  vector<int> a(n);
  for (auto&& e : a) cin >> e >> e;
  vector<int> v;
  for (auto e : a) {
    e %= m / 2;
    v.push_back(e);
    v.push_back(e + m / 2);
  }
  sort(begin(v), end(v));
  int mn = n + 1, me = -1;
  for (auto e : v) {
    if (e >= m / 2) break;
    ++e;
    int cur = lower_bound(begin(v), end(v), e + k) - lower_bound(begin(v), end(v), e);
    if (cur < mn) {
      mn = cur;
      me = e;
    }
  }
  cout << mn << ' ' << (me + k) % (m / 2) << '\n';
  bool first = true;
  for (int i = 0; i < n; ++i) {
    a[i] %= m / 2;
    if ((me <= a[i] and a[i] < me + k) or (me <= a[i] + m / 2 and a[i] + m / 2 < me + k)) {
      if (not exchange(first, false)) {
        cout << ' ';
      }
      cout << i + 1;
    }
  }
  cout << '\n';
}