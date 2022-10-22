#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + (s[i] == '1');
    }
    int k = pref[n];
    // k / n = c / m
    long long c = (long long) k * m;
    if (c % n != 0) {
      cout << -1 << '\n';
      continue;
    }
    c /= n;
    int res = -1;
    for (int i = 0; i <= n - m; i++) {
      if (pref[i + m] - pref[i] == c) {
        res = i;
        break;
      }
    }
    if (res != -1) {
      cout << 1 << '\n';
      cout << res + 1 << " " << res + m << '\n';
      continue;
    }
    for (int i = 0; i <= n - (n - m); i++) {
      if (pref[i + (n - m)] - pref[i] == k - c) {
        res = i;
        break;
      }
    }
    if (res != -1) {
      cout << 2 << '\n';
      cout << 1 << " " << res << '\n';
      cout << res + (n - m) + 1 << " " << n << '\n';
      continue;
    }
    assert(false);
  }
  return 0;
}