#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T, class U> void assign(V<T>& v, int n, const U& a) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


bool chk(const string& s) {
  int n = s.size();
  for (int i = 0; i < n / 2; ++i) {
    if (s[i] != s[n - 1 - i]) return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  if (n & 1) {
    int c = 0;
    for (int i = 0; i < n; ++i) if (i != n / 2) {
      c += s[i] == s[0];
    }
    if (c == n - 1) return cout << "Impossible" << '\n', 0;
  } else {
    if (count(begin(s), end(s), s[0]) == n) return cout << "Impossible" << '\n', 0;
  }
  s += s;
  for (int i = 0; i < n; ++i) {
    if (s.substr(0, n) != s.substr(i, n) and chk(s.substr(i, n))) return cout << 1 << '\n', 0;
  }
  cout << 2 << '\n';
}