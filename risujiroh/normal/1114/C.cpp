#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


template<class Int> map<Int, int> factor(Int n) {
  map<Int, int> res;
  for (Int i = 2; i * i <= n; ++i) while (n % i == 0) ++res[i], n /= i;
  if (n != 1) ++res[n];
  return res;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  lint n, b; cin >> n >> b;
  lint res = 9e18;
  for (const auto& el : factor(b)) {
    lint p = el.first, e = el.second;
    lint s = 0;
    for (lint m = n / p; m > 0; m /= p) {
      s += m;
    }
    res = min(res, s / e);
  }
  cout << res << '\n';
}