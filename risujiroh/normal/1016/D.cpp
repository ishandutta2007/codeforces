#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V  = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  V<> b(m); for (int i = 0; i < m; i++) cin >> b[i];
  int xa = 0; for (int i = 0; i < n; i++) xa ^= a[i];
  int xb = 0; for (int i = 0; i < m; i++) xb ^= b[i];
  if (not (xa == xb)) return cout << "NO" << '\n', 0;
  VV<> c(n, V<>(m));
  for (int k = 0; k < 30; k++) {
    for (int i = 0; i < n - 1; i++) c[i][0] += (a[i] & 1 << k);
    for (int j = 1; j < m; j++) c[n - 1][j] += (b[j] & 1 << k);
  }
  c[n - 1][0] = b[0]; for (int i = 0; i < n - 1; i++) c[n - 1][0] ^= c[i][0];
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cout << c[i][j] << ' ';
    cout << '\n';
  }
}