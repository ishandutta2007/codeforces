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
  int n; cin >> n; cin.ignore();
  string s; getline(cin, s);
  if (n & 1) return cout << 0 << '\n', 0;
  int x = count(begin(s), end(s), '('), y = n - x;
  if (abs(x - y) != 2) return cout << 0 << '\n', 0;
  V<> a(n + 1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') a[i + 1] = a[i] + 1;
    else a[i + 1] = a[i] - 1;
  }
  V<> l(n + 1, 1e9), r(n + 1, 1e9);
  l[0] = a[0];
  for (int i = 0; i < n; ++i) {
    l[i + 1] = min(l[i], a[i + 1]);
  }
  r[n] = a[n];
  for (int i = n - 1; i >= 0; --i) {
    r[i] = min(r[i + 1], a[i]);
  }
  int res = 0;
  if (x > y) {
    if (a[n] != 2) return cout << 0 << '\n', 0;
    for (int i = 0; i < n; ++i) if (s[i] == '(') {
      res += l[i] >= 0 and r[i + 1] >= 2;
    }
  } else {
    if (a[n] != -2) return cout << 0 << '\n', 0;
    for (int i = 0; i < n; ++i) if (s[i] == ')') {
      res += l[i] >= 0 and r[i + 1] >= -2;
    }
  }
  cout << res << '\n';
}