#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n);
  std::vector<std::tuple<int, int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &std::get<0>(v[i]));
  }
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &std::get<1>(v[i]));
    std::get<2>(v[i]) = i + 1;
  }
  std::sort(v.begin(), v.end());
  std::reverse(v.begin(), v.end());
  printf("%d\n%d", n / 2 + 1, std::get<2>(v[0]));
  for (int i = 1; i + 1 < v.size(); i += 2) {
    if (std::get<1>(v[i]) >= std::get<1>(v[i + 1])) {
      printf(" %d", std::get<2>(v[i]));
    } else {
      printf(" %d", std::get<2>(v[i + 1]));
    }
  }
  if (n % 2 == 0) {
    printf(" %d", std::get<2>(v[n - 1]));
  }
  puts("");
  return 0;
}