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
  int n, m;
  cin >> n >> m;
  int mn = n;
  while (m--) {
    int l, r;
    cin >> l >> r;
    mn = min(mn, r - l + 1);
  }
  cout << mn << '\n';
  for (int i = 0; i < n; ++i) {
    cout << i % mn << " \n"[i == n - 1];
  }
}