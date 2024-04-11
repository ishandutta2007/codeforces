#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

template<class T, class U = int> T dsum(T n, U b = 10) { return n ? n % b + dsum(n / b, b) : 0; }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n; cin >> n;
  lint a = 0;
  while (10 * a + 9 < n) a = 10 * a + 9;
  int res = dsum(a) + dsum(n - a);
  cout << res << '\n';
}