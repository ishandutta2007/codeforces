#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  string s; cin >> s;
  int n = s.size();
  for (int i = 0; i < n - 1; ++i) {
    if (s[i] != s[i + 1]) {
      for (int j = 0; j < i - j; ++j) swap(s[j], s[i - j]);
      cout << 1 << ' ';
    } else cout << 0 << ' ';
  }
  cout << (s[n - 1] == 'a') << '\n';
}