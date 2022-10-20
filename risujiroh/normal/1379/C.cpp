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
  int tt;
  cin >> tt;
  while (tt--) {
    using ll = long long;
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i];
    }
    auto v = a;
    sort(begin(v), end(v));
    vector<ll> cum(m + 1);
    for (int i = m; i--; ) {
      cum[i] = v[i] + cum[i + 1];
    }
    ll res = 0;
    for (int i = 0; i < m; ++i) {
      ll p = upper_bound(begin(v), end(v), b[i]) - begin(v);
      p = max(p, m - n);
      ll cur = cum[p] - cum[m];
      cur += (n - (m - p)) * b[i];
      if (p == m or a[i] < v[p]) {
        cur -= p < m ? (n - m + p > 0 ? min(v[p], b[i]) : v[p]) : b[i];
        cur += a[i];
      }
      res = max(res, cur);
    }
    cout << res << '\n';
  }
}