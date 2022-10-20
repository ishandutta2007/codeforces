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
    int n, m;
    cin >> n >> m;
    if (n == 1) {
      cout << "0\n";
    } else if (n == 2) {
      cout << m << '\n';
    } else {
      cout << 2 * m << '\n';
    }
  }
}