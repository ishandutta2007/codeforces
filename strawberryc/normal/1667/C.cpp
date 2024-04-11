#include <bits/stdc++.h>

int n;

int main() {
  std::cin >> n;
  std::cout << (2 * n + 1) / 3 << std::endl;
  int k = (2 * n + 1) / 3;
  for (int x = n - k + 1, y = n - k + 1; x <= n; x += 2, y++)
    printf("%d %d\n", x, y);
  for (int x = k & 1 ? n - 1 : n, y = n; x > n - k; x -= 2, y--)
    printf("%d %d\n", x, y);
  return 0;
}