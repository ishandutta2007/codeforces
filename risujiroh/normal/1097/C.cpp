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
  V<> l(500'001), r(500'001);
  int cnt = 0;
  while (n--) {
    string s; cin >> s;
    int m = s.size();
    int x = count(begin(s), end(s), '('), y = m - x;
    if (x == y) {
      int t = 0;
      bool valid = true;
      for (int i = 0; i < m; ++i) {
        if (s[i] == '(') ++t;
        else --t;
        if (t < 0) {
          valid = false;
          break;
        }
      }
      cnt += valid;
    } else if (x > y) {
      int t = 0;
      bool valid = true;
      for (int i = 0; i < m; ++i) {
        if (s[i] == '(') ++t;
        else --t;
        if (t < 0) {
          valid = false;
          break;
        }
      }
      if (valid) ++l[t];
    } else {
      int t = 0;
      bool valid = true;
      for (int i = 0; i < m; ++i) {
        if (s[m - 1 - i] == ')') ++t;
        else --t;
        if (t < 0) {
          valid = false;
          break;
        }
      }
      if (valid) ++r[t];
    }
  }
  int res = 0;
  for (int x = 0; x <= 500'000; ++x) {
    res += min(l[x], r[x]);
  }
  res += cnt / 2;
  cout << res << '\n';
}