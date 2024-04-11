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
  string s; cin >> s;
  V<> l(n), r(n);
  int t = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'G') l[i] = ++t;
    else t = 0;
  }
  t = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'G') r[i] = ++t;
    else t = 0;
  }
  int res = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'G') res = max(res, l[i] + r[i] - 1);
    else {
      if (i == 0) res = max(res, r[i + 1] + 1);
      else if (i == n - 1) res = max(res, l[i - 1] + 1);
      else res = max(res, l[i - 1] + 1 + r[i + 1]);
    }
  }
  res = min(res, count(begin(s), end(s), 'G'));
  cout << res << '\n';
}