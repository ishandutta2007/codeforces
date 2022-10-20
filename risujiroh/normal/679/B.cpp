#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll cb(ll x) {
  return x * x * x;
}

map<ll, pair<ll, ll>> mp;
pair<ll, ll> f(ll m) {
  if (m < 8) {
    return {m, m};
  }
  if (mp.count(m)) {
    return mp[m];
  }
  ll ok = 2, ng = 1e5 + 1;
  while (ng - ok > 1) {
    ll mid = (ok + ng ) / 2;
    (cb(mid) <= m ? ok : ng) = mid;
  }
  auto [a, b] = f(m - cb(ok));
  return mp[m] = max<pair<ll, ll>>({a + 1, b + cb(ok)}, f(cb(ok) - 1));
}

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  ll m;
  cin >> m;
  auto [a, b] = f(m);
  cout << a << ' ' << b << '\n';
}