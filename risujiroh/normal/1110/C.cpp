#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


template<class Int> V<Int> divisor(Int n) {
  V<Int> res;
  Int i;
  for (i = 1; i * i < n; ++i) if (n % i == 0) res.push_back(i), res.push_back(n / i);
  if (i * i == n) res.push_back(i);
  sort(rbegin(res), rend(res));
  return res;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int q; cin >> q;
  V<> t(26);
  for (int i = 2; i <= 25; ++i) {
    auto ds = divisor((1 << i) - 1);
    t[i] = ds[1];
  }
  while (q--) {
    int a; cin >> a;
    int res = (1 << __lg(a) + 1) - 1;
    if (res == a) {
      res = t[__lg(a) + 1];
    }
    cout << res << '\n';
  }
}