#include <bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using lint = long long int;
using ulint = unsigned long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, x, y; cin >> n >> x >> y;
  V<> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  if (x > y) {
    return cout << n << '\n', 0;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    res += a[i] <= x;
  }
  res = (res + 1) / 2;
  cout << res << '\n';
}