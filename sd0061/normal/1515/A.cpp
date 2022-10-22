#include <bits/stdc++.h>

int main() {
  int T, N, M;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &N, &M);
    std::vector<int> a(N);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a.begin(), a.end());
    bool f = false;
    for (int i = 0; i < N; ++i) {
      sum += a[i];
      if (sum == M) {
        if (i + 1 < N) {
          std::swap(a[i], a[i + 1]);
          break;
        } else {
          f = 1;
          break;
        }
      }
    }
    if (f) {
      puts("NO");
    } else {
      puts("YES");
      for (int i = 0; i < N; ++i) {
        printf("%d%c", a[i], " \n"[i + 1 == N]);
      }
    }
  }
}