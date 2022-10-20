#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;

using i128 = lint;
// using i128 = __int128;

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  int n; cin >> n;
  lint k; cin >> k;
  string s; cin >> s;
  VV<i128> dp(n, V<i128>(n + 1));
  for (int i = 0; i < n; ++i) {
    dp[i][1] = 1;
    V<bool> b(26);
    for (int j = i - 1; j >= 0; --j) if (!b[s[j] - 'a']) {
      b[s[j] - 'a'] = true;
      for (int l = 1; l <= i; ++l) {
        dp[i][l + 1] += dp[j][l];
      }
    }
  }
  V<bool> b(26);
  V<i128> a(n + 1);
  a[0] = 1;
  for (int i = n - 1; i >= 0; --i) if (!b[s[i] - 'a']) {
    b[s[i] - 'a'] = true;
    for (int l = 1; l <= i + 1; ++l) a[l] += dp[i][l];
  }
  lint res = 0;
  for (int l = n; l >= 0; --l) {
    lint t = min(a[l], k);
    res += (n - l) * t;
    k -= t;
    if (!k) break;
  }
  cout << (k ? -1 : res) << '\n';
}