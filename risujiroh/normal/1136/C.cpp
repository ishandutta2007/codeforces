#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n, m; cin >> n >> m;
  VV<> a(n, V<>(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];
  VV<> b(n, V<>(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> b[i][j];
  for (int k = 0; k < n + m - 1; ++k) {
    V<> va, vb;
    for (int i = 0; i < n; ++i) {
      int j = k - i;
      if (j < 0 or j >= m) continue;
      va.push_back(a[i][j]);
      vb.push_back(b[i][j]);
    }
    sort(begin(va), end(va));
    sort(begin(vb), end(vb));
    if (va != vb) return cout << "NO" << '\n', 0;
  }
  cout << "YES" << '\n';
}