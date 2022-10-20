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
    V<> a(n), b(n); for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
    V<lint> dp(3);
    dp[1] = b[0];
    dp[2] = 2 * b[0];
    for (int i = 1; i < n; ++i) {
      V<lint> ndp(3, 1e18);
      for (int x = 0; x < 3; ++x) for (int y = 0; y < 3; ++y) {
        if (a[i - 1] + x == a[i] + y) continue;
        ndp[y] = min(ndp[y], dp[x] + y * b[i]);
      }
      swap(dp, ndp);
    }
    cout << *min_element(begin(dp), end(dp)) << '\n';
  }
}