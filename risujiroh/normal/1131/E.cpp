#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define int lint
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> dp(26);
  int bit = 0;
  for (int _ = 0; _ < n; ++_) {
    string p; cin >> p;
    int m = p.size();
    V<> ndp(26);
    if (count(begin(p), end(p), p[0]) == m) {
      for (int j = 0; j < 26; ++j) if (j == p[0] - 'a') {
        ndp[j] = dp[j] + m * (dp[j] + 1);
      } else {
        ndp[j] = !!(bit & 1 << j);
      }
    } else {
      int l = 0;
      while (p[l] == p[0]) ++l;
      int r = m - 1;
      while (p[r] == p[m - 1]) --r;
      r = m - 1 - r;
      if (p[0] == p[m - 1]) {
        for (int j = 0; j < 26; ++j) if (bit & 1 << j) {
          if (j == p[0] - 'a') {
            ndp[j] = r + 1 + l;
          } else {
            ndp[j] = 1;
          }
        }
      } else {
        for (int j = 0; j < 26; ++j) if (bit & 1 << j) {
          if (j == p[0] - 'a') {
            ndp[j] = 1 + l;
          } else if (j == p[m - 1] - 'a') {
            ndp[j] = r + 1;
          } else {
            ndp[j] = 1;
          }
        }
      }
    }
    int t = 0;
    for (int i = 0; i < m; ++i) {
      ++t;
      if (i == m - 1 or p[i] != p[i + 1]) {
        ndp[p[i] - 'a'] = max(ndp[p[i] - 'a'], t);
        t = 0;
      }
      bit |= 1 << p[i] - 'a';
    }
    swap(dp, ndp);
  }
  cout << *max_element(begin(dp), end(dp)) << '\n';
}