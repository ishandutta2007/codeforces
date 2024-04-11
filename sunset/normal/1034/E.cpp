#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  vector<long long> c(1 << n), d(1 << n);
  for (int i = 0; i < 1 << n; ++i) {
    c[i] = (a[i] - '0') * (1ll << (__builtin_popcount(i) << 1));
    d[i] = (b[i] - '0') * (1ll << (__builtin_popcount(i) << 1));
  }
  for (int i = 1; i < 1 << n; i <<= 1) {
    for (int j = 0; j < 1 << n; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        c[j + k + i] += c[j + k];
        d[j + k + i] += d[j + k];
      }
    }
  }
  for (int i = 0; i < 1 << n; ++i) {
    c[i] = c[i] * d[i];
  }
  for (int i = 1; i < 1 << n; i <<= 1) {
    for (int j = 0; j < 1 << n; j += i << 1) {
      for (int k = 0; k < i; ++k) {
        c[j + k + i] -= c[j + k];
      }
    }
  }
  for (int i = 0; i < 1 << n; ++i) {
    putchar((c[i] >> (__builtin_popcount(i) << 1) & 3) + '0');
  }
  putchar(10);
  return 0;
}