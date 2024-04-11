#include <bits/stdc++.h>

int main() {
  int T, N, L, R;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &N, &L, &R);
    std::vector<int> cnt(N + 1);
    for (int i = 0; i < L; ++i) {
      int x;
      scanf("%d", &x);
      cnt[x]++;
    }
    for (int i = 0; i < R; ++i) {
      int x;
      scanf("%d", &x);
      cnt[x]--;
    }
    int res = 0, sl = 0, sr = 0, pl = 0, pr = 0;
    for (int i = 1; i <= N; ++i) {
      // printf("%d %d\n", i, cnt[i]);
      if (cnt[i] > 0) {
        // res += cnt[i] / 2;
        // cnt[i] %= 2;
        sl += cnt[i];
        pl += cnt[i] / 2;
      } else if (cnt[i] < 0) {
        cnt[i] = -cnt[i];
        // res += cnt[i] / 2;
        // cnt[i] %= 2;
        sr += cnt[i];
        pr += cnt[i] / 2;
      }
    }
    // printf("%d %d\n", pl, pr);
    // printf("%d %d\n", sl, sr);
    int p = std::min(sr, sl);
    res += p;
    sl -= p;
    sr -= p;

    if (!sl) {
      std::swap(sl, sr);
      std::swap(pl, pr);
    }
    if (sl <= pl * 2) {
      res += sl / 2;
    } else {
      res += pl;
      sl -= pl * 2;
      res += sl;
    }

    printf("%d\n", res);
  }
}