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
  cout << fixed << setprecision(20);
  int n, h;
  cin >> n >> h;
  for (int i = 1; i < n; ++i) {
    cout << h * sqrt(i) / sqrt(n) << " \n"[i == n - 1];
  }
}