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
  int t; cin >> t;
  auto chk = [](const string& s) -> bool {
    int n = s.size();
    for (int i = 0; i < n; ++i) if (s[i] != s[n - 1 - i]) return false;
    return true;
  };
  for (int _ = 0; _ < t; ++_) {
    string s; cin >> s;
    sort(begin(s), end(s));
    if (chk(s)) cout << -1 << '\n';
    else cout << s << '\n';
  }
}