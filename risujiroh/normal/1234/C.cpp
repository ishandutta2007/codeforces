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
    string s, t; cin >> s >> t;
    V<> dp(2);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      V<> ndp(2);
      if (dp[0]) {
        ndp[0] |= s[i] < '3';
        ndp[1] |= s[i] >= '3' and t[i] >= '3';
      }
      if (dp[1]) {
        ndp[0] |= s[i] >= '3' and t[i] >= '3';
        ndp[1] |= t[i] < '3';
      }
      swap(dp, ndp);
    }
    cout << (dp[1] ? "YES" : "NO") << '\n';
  }
}