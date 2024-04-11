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
  string s;
  cin >> s;
  string t = "CODEFORCES";
  int n = size(s), m = size(t);
  if (n >= m) {
    for (int x = 0; x <= m; ++x) {
      int y = m - x;
      string a = s.substr(0, x) + s.substr(n - y);
      if (a == t) {
        cout << "YES\n";
        exit(0);
      }
    }
  }
  cout << "NO\n";
}