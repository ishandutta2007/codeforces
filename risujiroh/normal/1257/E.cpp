#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int k[3]; cin >> k[0] >> k[1] >> k[2];
  int n = k[0] + k[1] + k[2];
  V<> a(n);
  for (int t = 0; t < 3; ++t) {
    while (k[t]--) {
      int x; cin >> x, --x;
      a[x] = t;
    }
  }
  V<> dp(3);
  for (int e : a) {
    V<> ndp(3);
    ndp[0] = dp[0] + (e == 0);
    ndp[1] = dp[1] + (e == 1);
    ndp[2] = dp[2] + (e == 2);
    ndp[1] = max(ndp[1], ndp[0]);
    ndp[2] = max(ndp[2], ndp[1]);
    swap(dp, ndp);
  }
  cout << n - dp[2] << '\n';
}