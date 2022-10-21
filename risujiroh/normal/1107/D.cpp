#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  int n; scanf("%d", &n);
  VV<bool> a(n, V<bool>(n));
  for (int i = 0; i < n; ++i) {
    char s[n]; scanf("%s", s);
    for (int j = 0; j < n / 4; ++j) {
      int x = stoi(string(1, s[j]), nullptr, 16);
      for (int k = 0; k < 4; ++k) {
        a[i][4 * j + k] = x & 1 << 3 - k;
      }
    }
  }
  VV<> c(n + 1, V<>(n + 1));
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    c[i + 1][j + 1] = c[i][j + 1] + c[i + 1][j] - c[i][j] + a[i][j];
  }

  int res = 0;
  for (int x = 1; x <= n; ++x) if (n % x == 0) {
    bool f = true;
    for (int i = 0; i < n; i += x) for (int j = 0; j < n; j += x) {
      int s = c[i + x][j + x] - c[i][j + x] - c[i + x][j] + c[i][j];
      if (s % (x * x)) f = false;
    }
    if (f) res = max(res, x);
  }
  cout << res << '\n';
}