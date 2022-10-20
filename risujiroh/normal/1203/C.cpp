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
  int n; cin >> n;
  V<lint> a(n); for (auto&& e : a) cin >> e;
  auto d = accumulate(begin(a), end(a), 0LL, [](lint x, lint y) { return __gcd(x, y); });
  cout << divisor(d).size() << '\n';
}