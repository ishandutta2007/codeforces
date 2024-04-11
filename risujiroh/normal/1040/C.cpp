#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  lint t; cin >> t;
  V<lint> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<> x(n); for (int i = 0; i < n; i++) cin >> x[i], x[i]--;
  V<lint> c(n), d(n, 9e18);
  for (int i = 0; i < n; i++) c[i] = a[i] + t;
  for (int i = 0; i < n; i++) {
    if (x[i] < i) return cout << "No" << '\n', 0;
    if (x[i] < n - 1) {
      d[x[i]] = min(d[x[i]], a[x[i] + 1] + t);
    }
    if (x[i] > i) {
      // c[x[i] - 1] = max(c[x[i] - 1], a[x[i]] + t);
      c[i] = max(c[i], a[i + 1] + t);
      // for (int j = x[i]; j > i; j--) {
      //   c[j - 1] = max(c[j - 1], a[j] + t);
      // }
    }
  }
  for (int i = 1; i < n; i++) {
    c[i] = max(c[i], c[i - 1] + 1);
  }
  for (int i = n - 2; i >= 0; i--) {
    d[i] = min(d[i], d[i + 1] - 1);
  }
  for (int i = 0; i < n; i++) {
    if (d[i] <= c[i]) return cout << "No" << '\n', 0;
  }
  cout << "Yes" << '\n';
  for (int i = 0; i < n; i++) cout << c[i] << (i != n - 1 ? ' ' : '\n');
}