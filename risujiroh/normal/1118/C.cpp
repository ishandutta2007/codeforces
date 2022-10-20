#include <bits/stdc++.h>
using namespace std;
using lint = long long;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;


int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;
  V<> c(1001);
  for (int i = 0; i < n * n; ++i) {
    int a; cin >> a;
    ++c[a];
  }
  VV<> res(n, V<>(n));
  if (n & 1) {
    int odd = 0;
    for (auto&& e : c) odd += e & 1;
    if (odd != 1) {
      return cout << "NO" << '\n', 0;
    }
    for (int a = 1; a <= 1000; ++a) if (c[a] & 1) {
      --c[a];
      res[n / 2][n / 2] = a;
    }
    int c2 = 0;
    for (auto&& e : c) c2 += e % 4 == 2;
    if (c2 > n - 1) {
      return cout << "NO" << '\n', 0;
    }
    int i = n / 2, j = 0;
    for (int a = 1; a <= 1000; ++a) if (c[a] % 4 == 2) {
      if (i == n / 2) {
        c[a] -= 2;
        res[i][j] = res[i][n - 1 - j] = a;
        if (++j == n / 2) i = 0;
      } else {
        c[a] -= 2;
        res[i][j] = res[n - 1 - i][j] = a;
        ++i;
      }
    }
    int a = 1;
    while (i != n / 2 or j != n / 2) {
      while (!c[a]) ++a;
      c[a] -= 2;
      if (i == n / 2) {
        res[i][j] = res[i][n - 1 - j] = a;
        if (++j == n / 2) i = 0;
      } else {
        res[i][j] = res[n - 1 - i][j] = a;
        ++i;
      }
    }
    a = 1;
    for (int i = 0; i < n / 2; ++i) for (int j = 0; j < n / 2; ++j) {
      while (!c[a]) ++a;
      c[a] -= 4;
      res[n - 1 - i][j] = res[i][n - 1 - j] = res[n - 1 - i][n - 1 - j] = res[i][j] = a;
    }
  } else {
    for (auto&& e : c) if (e % 4) {
      return cout << "NO" << '\n', 0;
    } else {
      e /= 4;
    }
    int a = 1;
    for (int i = 0; i < n / 2; ++i) for (int j = 0; j < n / 2; ++j) {
      while (!c[a]) ++a;
      --c[a];
      res[i][j] = a;
      res[n - 1 - i][j] = res[i][n - 1 - j] = res[n - 1 - i][n - 1 - j] = res[i][j];
    }
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    cout << res[i][j] << " \n"[j == n - 1];
  }
}