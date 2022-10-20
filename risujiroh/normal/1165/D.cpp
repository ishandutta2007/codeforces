#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

template<class Z> V<Z> divisor(Z n) {
  V<Z> res;
  Z i;
  for (i = 1; i * i < n; ++i) if (n % i == 0) res.push_back(i), res.push_back(n / i);
  if (i * i == n) res.push_back(i);
  sort(begin(res), end(res));
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    V<lint> d(n); for (auto&& e : d) cin >> e;
    sort(begin(d), end(d));
    auto chk = [&](lint x) -> bool {
      auto ds = divisor(x);
      V<lint> v(begin(ds) + 1, end(ds) - 1);
      if (d == v) {
        cout << x << '\n';
        return true;
      }
      return false;
    };
    if (chk(d[0] * d.back())) continue;
    cout << -1 << '\n';
  }
}