#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    V<> x(n), y(n);
    VV<> f(n, V<>(4));
    int lx = -1e5, ux = 1e5;
    int ly = -1e5, uy = 1e5;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
      for (auto&& e : f[i]) cin >> e;
      if (!f[i][0]) {
        if (ux < x[i]) ok = false;
        lx = max(lx, x[i]);
      }
      if (!f[i][2]) {
        if (lx > x[i]) ok = false;
        ux = min(ux, x[i]);
      }
      if (!f[i][3]) {
        if (uy < y[i]) ok = false;
        ly = max(ly, y[i]);
      }
      if (!f[i][1]) {
        if (ly > y[i]) ok = false;
        uy = min(uy, y[i]);
      }
    }
    if (!ok) cout << 0 << '\n';
    else cout << 1 << ' ' << lx << ' ' << ly << '\n';
  }
}