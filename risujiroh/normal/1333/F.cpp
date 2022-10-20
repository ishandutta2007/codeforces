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
  if (n == 3) {
    cout << "1 1\n";
    exit(0);
  }
  vector<int> res(n + 1);
  int k = n / 2, m = 2 * k;
  vector<bool> b(n + 1);
  for (int i = n; i >= 2; --i) {
    while (b[m]) {
      if (m > 2 * k) {
        m -= k;
      } else {
        --k;
        m = n / k * k;
      }
    }
    DEBUG(k, m);
    res[i] = k;
    b[m] = true;
  }
  for (int i = 2; i <= n; ++i) {
    cout << res[i] << " \n"[i == n];
  }
}