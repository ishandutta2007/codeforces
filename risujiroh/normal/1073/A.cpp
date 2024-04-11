#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  for (int i = 0; i < n - 1; ++i) if (s[i] != s[i + 1]) return cout << "YES\n" << s.substr(i, 2) << '\n', 0;
  cout << "NO" << '\n';
}