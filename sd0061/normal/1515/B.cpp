#include <bits/stdc++.h>

int main() {
  int T, N, M;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &N);
    bool f = 0;
    if (N % 4 == 0) {
      int M = sqrt(N / 4);
      while (4 * M * M < N) {
        ++M;
      }
      if (4 * M * M == N) {
        f = 1;
      }
    }
    if (N % 2 == 0) {
      int M = sqrt(N / 2);
      while (2 * M * M < N) {
        ++M;
      }
      if (2 * M * M == N) {
        f = 1;
      }
    }
    puts(f ? "YES" : "NO");
  }
}