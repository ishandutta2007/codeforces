#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  if (n == 1) return cout << "Yes" << '\n', 0;
  string s; cin >> s;
  V<> c(26);
  for (int i = 0; i < n; i++) c[s[i] - 'a']++;
  for (auto&& i : c) if (i >= 2) return cout << "Yes" << '\n', 0;
  cout << "NO" << '\n';
}