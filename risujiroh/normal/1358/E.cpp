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
  int m = (n + 1) / 2;
  vector<long long> c(m + 1);
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    c[i + 1] = c[i] + a;
  }
  long long x;
  cin >> x;
  vector<long long> d(m + 1);
  for (int i = 0; i <= m; ++i) {
    d[i] = c[i] - i * x;
    if (i) {
      d[i] = max(d[i], d[i - 1]);
    }
  }
  for (int k = m; k <= n; ++k) {
    if (d[n - k] < c[m] + (k - m) * x) {
      cout << k << '\n';
      exit(0);
    }
  }
  cout << "-1\n";
}