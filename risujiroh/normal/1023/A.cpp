#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int m, n; cin >> m >> n;
  string s, t; cin >> s >> t;
  bool ast = false;
  for (int i = 0; i < m; i++) if (s[i] == '*') ast = true;
  if (ast) {
    int p;
    for (int i = 0; i < m; i++) if (s[i] == '*') p = i;
    if (s.substr(0, p) != t.substr(0, p)) cout << "NO" << '\n';
    else {
      s.erase(s.begin(), s.begin() + p);
      t.erase(t.begin(), t.begin() + p);
      reverse(s.begin(), s.end()), reverse(t.begin(), t.end());
      if (s.substr(0, m - p - 1) != t.substr(0, m - p - 1)) cout << "NO" << '\n';
      else cout << "YES" << '\n';
    }
  } else {
    cout << (s == t ? "YES" : "NO") << '\n';
  }
}