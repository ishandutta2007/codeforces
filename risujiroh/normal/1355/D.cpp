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
  int n, s;
  cin >> n >> s;
  if (s < 2 * n) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
      if (i == n - 1) {
        cout << s << '\n';
      } else {
        cout << "2 ";
        s -= 2;
      }
    }
    cout << "1\n";
  }
}