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
  V<string> s(n); for (int i = 0; i < n; i++) cin >> s[i];
  int i1 = n, i2 = -1, j1 = m, j2 = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'B') {
        i1 = min(i1, i);
        i2 = max(i2, i);
        j1 = min(j1, j);
        j2 = max(j2, j);
      }
    }
  }
  cout << (i1 + i2) / 2 + 1 << ' ' << (j1 + j2) / 2 + 1 << '\n';
}