#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define DEBUG(...)
#endif

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(26);
    for (char c : s) {
      ++cnt[c - 'a'];
    }
    for (int m = n; m; --m) {
      int g = gcd(m, k);
      int c = 0;
      for (int i = 0; i < 26; ++i) {
        c += cnt[i] / (m / g) * (m / g);
      }
      if (c >= m) {
        cout << m << '\n';
        break;
      }
    }
  }
}