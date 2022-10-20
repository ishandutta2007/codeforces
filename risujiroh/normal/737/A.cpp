#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

template <class T> constexpr T inf = numeric_limits<T>::max() / 2.1;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  using ll = long long;
  ll n, k, s, t;
  cin >> n >> k >> s >> t;
  vector<ll> c(n), v(n);
  for (int i = 0; i < n; ++i) {
    cin >> c[i] >> v[i];
  }
  vector<ll> g(k);
  for (auto&& e : g) cin >> e;
  g.push_back(0);
  g.push_back(s);
  sort(begin(g), end(g));
  vector<ll> d(k + 1);
  for (int i = 0; i <= k; ++i) {
    d[i] = g[i + 1] - g[i];
  }
  sort(begin(d), end(d));
  vector<int> ord(n);
  iota(begin(ord), end(ord), 0);
  sort(begin(ord), end(ord), [&](int i, int j) {
    return v[i] > v[j];
  });
  DEBUG(d);
  int res = inf<int>;
  ll cur = s, cnt = 0;
  int ptr = k + 1;
  for (int i : ord) {
    if (v[i] < d.back()) break;
    DEBUG(d[ptr - 1], v[i]);
    while (ptr and 2 * d[ptr - 1] >= v[i]) {
      DEBUG(v[i], ptr);
      --ptr;
      cur += 2 * d[ptr];
      ++cnt;
    }
    DEBUG(v[i], cur, cnt);
    DEBUG(v[i], cur - cnt * v[i]);
    if (cur - cnt * v[i] <= t) {
      res = min<int>(res, c[i]);
    }
  }
  if (res == inf<int>) {
    res = -1;
  }
  cout << res << '\n';
}