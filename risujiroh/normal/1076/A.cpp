#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... Args> void assign(V<T>& v, int n, const Args&... args) { v.resize(n); for (auto&& e : v) assign(e, args...); }


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  string s; cin >> s;
  for (int i = 0; i < n; ++i) {
    if (i == n - 1 or s[i] > s[i + 1]) {
      s.erase(next(begin(s), i));
      cout << s << '\n';
      return 0;
    }
  }
}