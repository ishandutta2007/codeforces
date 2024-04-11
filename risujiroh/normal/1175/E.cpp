#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  constexpr int N = 5e5;
  int n, m; cin >> n >> m;
  VV<> a(20, V<>(N + 1, -1));
  while (n--) {
    int l, r; cin >> l >> r;
    a[0][l] = max(a[0][l], r);
  }
  for (int i = 1; i <= N; ++i) a[0][i] = max(a[0][i], a[0][i - 1]);
  for (int k = 1; k < 20; ++k) {
    for (int i = 0; i <= N; ++i) if (a[k - 1][i] != -1) {
      a[k][i] = a[k - 1][a[k - 1][i]];
    }
  }
  while (m--) {
    int x, y; cin >> x >> y;
    if (a.back()[x] < y) {
      cout << -1 << '\n';
      continue;
    }
    int res = 0, t = x;
    for (int k = 19; k >= 0; --k) {
      if (a[k][t] < y) {
        t = a[k][t];
        res += 1 << k;
      }
    }
    cout << res + 1 << '\n';
  }
}