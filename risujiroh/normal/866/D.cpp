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
  vector<int> a(n);
  for (auto&& e : a) cin >> e;
  using ll = long long;
  multiset<ll, greater<>> ms;
  ll off = 0, res = 0;
  for (int i = 1; i < n; ++i) {
    int d = a[i] - a[i - 1];
    off += d;
    ms.insert(d - off);
    ms.insert(d - off);
    ms.erase(begin(ms));
    res += max(off + *begin(ms), 0LL);
  }
  cout << res << '\n';
}