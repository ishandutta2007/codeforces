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
    int n;
    cin >> n;
    if (n % 4) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 0; i < n; ++i) {
        int a = i < n / 2 ? 2 * i + 2 : i < n / 4 * 3 ? 2 * (i - n / 2) + 1 : 2 * (i - n / 2) + 3;
        cout << a << " \n"[i == n - 1];
      }
    }
  }
}