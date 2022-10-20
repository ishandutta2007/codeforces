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
  int n, m; cin >> n >> m;
  V<> a(m); for (int i = 0; i < m; ++i) cin >> a[i], --a[i];
  V<> c(n);
  int s = 0;
  string res(m, '0');
  for (int i = 0; i < m; ++i) {
    if (c[a[i]] == 0) ++s;
    ++c[a[i]];
    if (s == n) {
      res[i] = '1';
      for (int j = 0; j < n; ++j) {
        --c[j];
        if (c[j] == 0) --s;
      }
    }
  }
  cout << res << '\n';
}