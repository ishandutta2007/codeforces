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
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  if (n != m) return cout << "No" << '\n', 0;
  string v = "aeiou";
  for (int i = 0; i < n; ++i) {
    bool b = find(begin(v), end(v), s[i]) != end(v);
    bool c = find(begin(v), end(v), t[i]) != end(v);
    if (b != c) return cout << "No" << '\n', 0;
  }
  cout << "Yes" << '\n';
}