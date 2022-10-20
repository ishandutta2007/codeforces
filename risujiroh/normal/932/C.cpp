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
  int n, a, b;
  cin >> n >> a >> b;
  for (int x = 0; a * x <= n; ++x) {
    if ((n - a * x) % b) continue;
    int y = (n - a * x) / b;
    DEBUG(x, y);
    vector<int> res(n);
    for (int i = 0; i < n; ++i) {
      if (i < a * x) {
        if (i % a) {
          res[i] = i - 1;
        } else {
          res[i] = i + a - 1;
        }
      } else {
        if ((i - a * x) % b) {
          res[i] = i - 1;
        } else {
          res[i] = i + b - 1;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      cout << res[i] + 1 << " \n"[i == n - 1];
    }
    exit(0);
  }
  cout << "-1\n";
}