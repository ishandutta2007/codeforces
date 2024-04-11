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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int last = -10;
    for (int i = 0; i < n; i++) {
      if (s[i] == '0') {
        int diff = i - last - 1;
        ans += max(0, 2 - diff);
        last = i;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}