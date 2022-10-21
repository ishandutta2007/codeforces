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
  return res;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  auto ds = divisor(n);
  V<lint> res;
  for (lint d : ds) {
    res.push_back(n / d * (n + 2 - d) / 2);
  }
  sort(begin(res), end(res));
  int m = res.size();
  for (int i = 0; i < m; ++i) {
    cout << res[i] << (i != m - 1 ? ' ' : '\n');
  }
}