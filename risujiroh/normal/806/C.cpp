#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  using ll = long long;
  int n;
  cin >> n;
  multiset<ll> ms;
  while (n--) {
    ll a;
    cin >> a;
    ms.insert(a);
  }
  auto chk = [&](ll mx) {
    for (ll i = 1; i < mx; i *= 2) {
      if (ms.find(i) == end(ms)) {
        return false;
      }
    }
    return true;
  };
  vector<int> res;
  int x = 0, cur = 0;
  while (true) {
    DEBUG(ms);
    if ((int)size(ms) <= x) {
      res.push_back(cur);
    }
    if (empty(ms)) break;
    ll mx = *prev(end(ms));
    if (chk(mx)) {
      x += (mx & (mx - 1)) == 0;
    } else {
      if (x == 0) {
        cout << "-1\n";
        exit(0);
      }
      --x;
      ms.erase(ms.find(mx));
      continue;
    }
    for (ll i = 1; i < mx; i *= 2) {
      ms.erase(ms.find(i));
    }
    ms.erase(ms.find(mx));
    ++cur;
  }
  res.erase(unique(begin(res), end(res)), end(res));
  int sz = size(res);
  for (int i = 0; i < sz; ++i) {
    cout << res[i] << " \n"[i == sz - 1];
  }
}