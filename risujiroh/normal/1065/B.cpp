#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, m; cin >> n >> m;
  lint mn = max(n - 2 * m, 0LL);
  lint mx;
  for (lint i = n; i >= 0; i--) {
    if (m <= (n - i) *(n - i - 1) / 2) {
      mx = i;
      break;
    }
  }
  cout << mn << ' ' << mx << '\n';
}