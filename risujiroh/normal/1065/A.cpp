#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int t; cin >> t;
  for (int it = 0; it < t; it++) {
    lint s, a, b, c; cin >> s >> a >> b >> c;
    lint res = s / c;
    res += res / a * b;
    cout << res << '\n';
  }
}