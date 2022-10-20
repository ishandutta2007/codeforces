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
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      a = abs(a);
      if (i & 1) {
        a = -a;
      }
      cout << a << " \n"[i == n - 1];
    }
  }
}