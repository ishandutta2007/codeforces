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
  VV<> t; assign(t, n, m);
  const V<> dx = {1, 1, 0, -1, -1, -1, 0, 1}, dy = {0, 1, 1, 1, 0, -1, -1, -1};
  for (int i = 1; i < n - 1; i++) for (int j = 1; j < m - 1; j++) {
    bool ok = true;
    for (int k = 0; k < 8; k++) {
      int x = i + dx[k], y = j + dy[k];
      if (s[x][y] == '.') ok = false;
    }
    if (ok) {
      for (int k = 0; k < 8; k++) {
        int x = i + dx[k], y = j + dy[k];
        t[x][y] = 1;
      }
    }
  }
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
    if (s[i][j] == '#' and !t[i][j] or s[i][j] == '.' and t[i][j]) return cout << "NO" << '\n', 0;
  }
  cout << "YES" << '\n';
}