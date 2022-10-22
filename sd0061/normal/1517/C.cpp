#include "bits/stdc++.h"

const int N = 505;
using int64 = long long;

int n, a[N], res[N][N];
int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    int k = 0;
    for (int j = 0; j < n; ++j) {
      if (a[j] > i) {
        res[i + k][k] = a[j];
        ++k;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      printf("%d%c", res[i][j], " \n"[j == i]);
    }
  }
}