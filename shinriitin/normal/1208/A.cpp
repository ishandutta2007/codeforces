#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    std::vector<int> ans = {a, b, a ^ b};
    printf("%d\n", ans[n % 3]);
  }
}