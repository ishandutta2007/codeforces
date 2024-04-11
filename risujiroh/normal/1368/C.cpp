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
  int n;
  cin >> n;
  cout << 3 * n + 4 << '\n';
  for (int i = 0; i <= n + 1; ++i) {
    cout << i << ' ' << i << '\n';
    if (i) {
      cout << i << ' ' << i - 1 << '\n';
      cout << i - 1 << ' ' << i << '\n';
    }
  }
}