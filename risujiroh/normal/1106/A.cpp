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
  V<string> s(n); for (int i = 0; i < n; ++i) cin >> s[i];
  int res = 0;
  for (int i = 1; i < n - 1; ++i) for (int j = 1; j < n - 1; ++j) {
    res += s[i][j] + s[i - 1][j - 1] + s[i - 1][j + 1] + s[i + 1][j - 1] + s[i + 1][j + 1] == 'X' * 5;
  }
  cout << res << '\n';
}