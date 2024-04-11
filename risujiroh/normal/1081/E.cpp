#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }

V<> divisor(int n) {
  V<> res;
  for (int i = 1; i * i <= n; ++i) if (n % i == 0) res.push_back(i);
  return res;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n, n >>= 1;
  V<> x(n); for (int i = 0; i < n; ++i) cin >> x[i];
  V<lint> n1(n), n2(n, 1e18);
  for (int d : divisor(x[0])) {
    if ((x[0] / d & 1) != (d & 1)) continue;
    lint _n1 = x[0] / d - d >> 1;
    lint _n2 = x[0] / d + d >> 1;
    if (_n1 > 0 and _n2 < n2[0]) {
      n1[0] = _n1;
      n2[0] = _n2;
    }
  }
  for (int i = 1; i < n; ++i) {
    for (int d : divisor(x[i])) {
      if ((x[i] / d & 1) != (d & 1)) continue;
      lint _n1 = x[i] / d - d >> 1;
      lint _n2 = x[i] / d + d >> 1;
      if (_n1 > n2[i - 1] and _n2 < n2[i]) {
        n1[i] = _n1;
        n2[i] = _n2;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (n2[i] == 1e18) return cout << "No" << '\n', 0;
  }
  cout << "Yes" << '\n';
  cout << n1[0] * n1[0] << ' ' << x[0];
  for (int i = 1; i < n; ++i) cout << ' ' << n1[i] * n1[i] - n2[i - 1] * n2[i - 1] << ' ' << x[i];
  cout << '\n';
}