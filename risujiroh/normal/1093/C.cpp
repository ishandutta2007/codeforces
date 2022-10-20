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
  V<lint> b(n >> 1); for (int i = 0; i < n >> 1; ++i) cin >> b[i];
  V<lint> a(n);
  a[0] = 0, a[n - 1] = b[0];
  for (int i = 1; i < n >> 1; ++i) {
    a[i] = a[i - 1];
    a[n - 1 - i] = b[i] - a[i];
    if (a[n - 1 - i] > a[n - i]) {
      a[n - 1 - i] = a[n - i];
      a[i] = b[i] - a[n - 1 - i];
    }
  }
  for (int i = 0; i < n; ++i) cout << a[i] << (i != n - 1 ? ' ' : '\n');
}