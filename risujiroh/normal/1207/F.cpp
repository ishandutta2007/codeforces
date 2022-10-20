#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  constexpr int n = 5e5, B = 512;
  V<> a(n);
  VV<> b(B);
  for (int k = 1; k < B; ++k) {
    b[k].resize(k);
  }

  int q; cin >> q;
  while (q--) {
    int tp, x, y; cin >> tp >> x >> y;
    if (tp == 1) {
      --x;
      a[x] += y;
      for (int k = 1; k < B; ++k) {
        b[k][x % k] += y;
      }
    } else {
      if (--y < 0) y += x;
      if (x < B) {
        cout << b[x][y] << '\n';
      } else {
        int res = 0;
        for (int i = y; i < n; i += x) {
          res += a[i];
        }
        cout << res << '\n';
      }
    }
  }
}