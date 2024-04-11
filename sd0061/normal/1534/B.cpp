#include <bits/stdc++.h>
const int N = 400005;
int n, a[N];
void work() {
  scanf("%d", &n);
  a[0] = a[n + 1] = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      int mx = a[i] - std::max(a[i - 1], a[i + 1]);
      a[i] -= mx;
      res += mx;
    }
  }
  for (int i = 0; i <= n; ++i) {
    res += std::abs(a[i] - a[i + 1]);
  }
  std::cout << res << std::endl;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}