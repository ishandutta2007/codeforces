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
  lint r; cin >> r, --r;
  if (!r) return cout << "NO" << '\n', 0;
  auto d = divisor(r);
  for (lint x : d) {
    lint z = r / x;
    if (z - x - 1 > 0 and ~(z - x - 1) & 1) {
      lint y = z - x - 1 >> 1;
      cout << x << ' ' << y << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
}