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
  int m = 1;
  while (m * m < n) m++;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + 1) * m - j <= n) cout << (i + 1) * m - j << ' ';
    }
  }
  cout << '\n';
}