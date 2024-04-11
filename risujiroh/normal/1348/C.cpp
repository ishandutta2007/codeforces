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
    sort(begin(s), end(s));
    if (s[0] != s[k - 1]) {
      cout << s[k - 1] << '\n';
    } else if (s[k] == s.back()) {
      for (int i = 0; i < n; i += k) {
        cout << s[i];
      }
      cout << '\n';
    } else {
      cout << s[0] + s.substr(k) << '\n';
    }
  }
}