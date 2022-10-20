#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int T; cin >> T;
  while (T--) {
    int n, x; cin >> n >> x;
    V<> d(n), h(n); for (int i = 0; i < n; ++i) cin >> d[i] >> h[i];
    int mxd = *max_element(begin(d), end(d));
    int mx = -2e9;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, d[i] - h[i]);
    }
    if (x <= mxd) {
      cout << 1 << '\n';
    } else {
      if (mx <= 0) {
        cout << -1 << '\n';
      } else {
        cout << 1 + (x - mxd + mx - 1) / mx << '\n';
      }
    }
  }
}