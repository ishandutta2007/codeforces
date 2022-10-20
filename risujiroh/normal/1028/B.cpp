#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  int k = max((n + 2) / 4, 1);
  string a(k, '5'), b(k, '4');
  b[k - 1] = '5';
  cout << a << '\n';
  cout << b << '\n';
}