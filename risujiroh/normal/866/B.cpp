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
  using ll = long long;
  ll n, ss;
  cin >> n >> ss;
  vector<ll> s(n), a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> a[i] >> b[i];
  }
  ll m = (accumulate(begin(s), end(s), 0LL) + ss - 1) / ss;
  ll ca = 0, cb = 0, ha = 0, hb = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] >= b[i]) {
      ca += s[i];
      ha += s[i] * a[i];
    } else {
      cb += s[i];
      hb += s[i] * b[i];
    }
  }
  if ((ca + ss - 1) / ss + (cb + ss - 1) / ss == m) {
    cout << ha + hb << '\n';
    exit(0);
  }
  ll ra = ca % ss, rb = cb % ss;
  ll res = 0;
  {
    vector<int> ord;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= b[i]) {
        ord.push_back(i);
      }
    }
    sort(begin(ord), end(ord), [&](int i, int j) {
      return a[i] - b[i] < a[j] - b[j];
    });
    ll cur = ha + hb;
    for (int i : ord) {
      auto t = min(ra, s[i]);
      ra -= t;
      cur -= (a[i] - b[i]) * t;
    }
    res = max(res, cur);
  }
  {
    vector<int> ord;
    for (int i = 0; i < n; ++i) {
      if (a[i] < b[i]) {
        ord.push_back(i);
      }
    }
    sort(begin(ord), end(ord), [&](int i, int j) {
      return b[i] - a[i] < b[j] - a[j];
    });
    ll cur = ha + hb;
    for (int i : ord) {
      auto t = min(rb, s[i]);
      rb -= t;
      cur -= (b[i] - a[i]) * t;
    }
    res = max(res, cur);
  }
  cout << res << '\n';
}