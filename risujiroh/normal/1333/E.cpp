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
  if (n < 3) {
    cout << "-1\n";
    exit(0);
  }
  vector res(n, vector<int>(n));
  int t = 1;
  for (int k = n; k-- > 3; ) {
    if (k & 1) {
      for (int j = 0; j <= k; ++j) {
        res[k][j] = t++;
      }
      for (int i = k; i--; ) {
        res[i][k] = t++;
      }
    } else {
      for (int i = 0; i <= k; ++i) {
        res[i][k] = t++;
      }
      for (int j = k; j--; ) {
        res[k][j] = t++;
      }
    }
  }
  res[0][0] = t++;
  res[0][1] = t++;
  res[1][0] = t++;
  res[1][1] = t++;
  res[0][2] = t++;
  res[2][1] = t++;
  res[2][2] = t++;
  res[1][2] = t++;
  res[2][0] = t++;
  for (auto&& v : res) {
    for (int i = 0; i < n; ++i) {
      cout << v[i] << " \n"[i == n - 1];
    }
  }
}