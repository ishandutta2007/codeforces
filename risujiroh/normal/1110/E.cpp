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
  int n; cin >> n;
  V<> c(n); for (int i = 0; i < n; ++i) cin >> c[i];
  V<> t(n); for (int i = 0; i < n; ++i) cin >> t[i];
  V<> dc(n - 1), dt(n - 1);
  for (int i = 0; i < n - 1; ++i) {
    dc[i] = c[i + 1] - c[i];
    dt[i] = t[i + 1] - t[i];
  }
  sort(begin(dc), end(dc));
  sort(begin(dt), end(dt));
  cout << (c[0] == t[0] and dc == dt ? "Yes" : "No") << '\n';
}