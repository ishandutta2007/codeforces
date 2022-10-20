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
  multiset<int> ms;
  while (n--) {
    int a;
    cin >> a;
    ms.insert(a);
  }
  vector<int> c(k + 1);
  for (int x = 1; x <= k; ++x) {
    cin >> c[x];
  }
  vector<vector<int>> res;
  while (not empty(ms)) {
    res.emplace_back();
    int cur = 0;
    while (true) {
      auto it = lower_bound(begin(c) + 1, end(c), cur, greater<>());
      if (it == begin(c) + 1) {
        break;
      }
      --it;
      int x = it - begin(c);
      auto nit = ms.upper_bound(x);
      if (nit != begin(ms)) {
        ++cur;
        --nit;
        res.back().push_back(*nit);
        ms.erase(nit);
      } else {
        break;
      }
      DEBUG(res);
    }
  }
  cout << size(res) << '\n';
  for (auto&& e : res) {
    cout << size(e);
    for (int f : e) {
      cout << ' ' << f;
    }
    cout << '\n';
  }
}