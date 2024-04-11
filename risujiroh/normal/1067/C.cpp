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
  for (int i = 0; i < n; ++i) switch (i % 3) {
    case 0 : cout << i / 3 * 2 << ' ' << 0 << '\n'; break;
    case 1 : cout << i / 3 * 2 + 1 << ' ' << -1 << '\n'; break;
    case 2 : cout << i / 3 * 2 + 1 << ' ' << 1 << '\n'; break;
  }
}