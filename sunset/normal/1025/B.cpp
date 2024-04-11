#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d", &a[i], &b[i]);
  }
  auto solve = [&](int x) {
    for (int i = 0; i < n; ++i) {
      if (a[i] % x != 0 && b[i] % x != 0) {
        return;
      }
    }
    printf("%d\n", x);
    exit(0);
  };
  auto check = [&](int x) {
    for (int i = 2; i * i <= x; ++i) {
      if (x % i == 0) {
        solve(i);
        while (x % i == 0) {
          x /= i;
        }
      }
    }
    if (x != 1) {
      solve(x);
    }
  };
  check(a[0]);
  check(b[0]);
  puts("-1");
  return 0;
}