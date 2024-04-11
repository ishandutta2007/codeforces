#include <bits/stdc++.h>

void work() {
  int n;
  scanf("%d", &n);
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  std::sort(a.begin(), a.end());
  long long res = 0, sum = 0;
  for (int i = 0; i < n; ++i) {
    res -= 1LL * i * a[i] - sum;
    sum += a[i];
  }
  for (int i = 1; i < n; ++i) {
    res += (a[i] - a[i - 1]);
  }
  printf("%lld\n", res);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}