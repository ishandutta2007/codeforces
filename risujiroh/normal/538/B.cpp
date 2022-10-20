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
  vector<int> res;
  while (n) {
    int t = n, x = 0, base = 1;
    while (t) {
      if (t % 10) {
        x += base;
      }
      t /= 10;
      base *= 10;
    }
    n -= x;
    res.push_back(x);
  }
  int m = size(res);
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << res[i] << " \n"[i == m - 1];
  }
}