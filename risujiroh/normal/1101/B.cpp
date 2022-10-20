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
  int n = s.size();
  int l = 0;
  while (l < n and s[l] != '[') ++l;
  while (l < n and s[l] != ':') ++l;
  int r = n - 1;
  while (r >= 0 and s[r] != ']') --r;
  while (r >= 0 and s[r] != ':') --r;
  if (l >= r) return cout << -1 << '\n', 0;
  int res = 4;
  for (int i = l; i <= r; ++i) {
    res += s[i] == '|';
  }
  cout << res << '\n';
}