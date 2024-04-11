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
  string s; cin >> s;
  V<string> t(5); for (int i = 0; i < 5; ++i) cin >> t[i];
  for (int i = 0; i < 5; ++i) {
    if (t[i][0] == s[0] or t[i][1] == s[1]) {
      return cout << "YES" << '\n', 0;
    }
  }
  cout << "NO" << '\n';
}