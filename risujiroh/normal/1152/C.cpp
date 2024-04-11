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
  lint a, b; cin >> a >> b;
  if (a == b) return cout << 0 << '\n', 0;
  if (a > b) swap(a, b);
  lint c = b - a, mn = 9e18, res = -1;
  for (lint d : divisor(c)) {
    lint curr = (a + d - 1) / d * d - a;
    lint l = (a + curr) / __gcd(a + curr, b + curr) * (b + curr);
    if (l < mn) {
      mn = l;
      res = curr;
    }
  }
  cout << res << '\n';
}