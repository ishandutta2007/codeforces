#include "bits/stdc++.h"

const int N = 200005;
using int64 = long long;

int main() {
  int64 n;
  std::vector<int64> v;
  unsigned long long x = 2050;

  for (int i = 0; i < 16; ++i) {
    v.emplace_back(x);
    x *= 10;
  }
  // std::cout << v.back() << std::endl;
  std::reverse(v.begin(), v.end());

  int T;
  std::cin >> T;
  while (T--) {
    std::cin >> n;
    int res = 0;
    for (auto &y : v) {
      while (n >= y) {
        n -= y;
        ++res;
      }
    }
    printf("%d\n", n == 0 ? res : -1);
  }
}