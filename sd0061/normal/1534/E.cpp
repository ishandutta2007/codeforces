#include <bits/stdc++.h>
const int N = 505;
int n, k;
int cnt[N];

void work() {
  bool wtf = false;
  scanf("%d%d", &n, &k);
  // if ((k & 1) && (~n & 1) && k * 2 > n) {
  //   wtf = true;
  //   k = n - k;
  // }
  int ans = -1;
  for (int a = 1; a <= 501; ++a) {
    if (a * k >= n && ((a * k) - n) % 2 == 0) {
      int delta = ((a * k - n) / 2 + n - 1) / n;
      if (delta * 2 + 1 > a) {
        continue;
      }
      ans = a;
      break;
    }
  }
  if (ans == -1) {
    puts("-1");
    fflush(stdout);
    return;
  }
  int p = ans * k;
  for (int i = 1; i <= n; ++i) {
    cnt[i] = 1;
    --p;
  }
  while (p > 0) {
    for (int i = 1; i <= n && p; ++i) {
      p -= 2;
      cnt[i] += 2;
    }
  }
  std::vector<std::pair<int, int>> v;
  for (int i = 1; i <= n; ++i) {
    v.emplace_back(cnt[i], i);
  }
  int res = 0;
  for (int w = 0; w < ans; ++w) {
    std::sort(v.begin(), v.end());
    std::reverse(v.begin(), v.end());
    printf("?");
    if (wtf) {
      for (int i = 0; i < k; ++i) {
        --v[i].first;
      }
      for (int i = k; i < n; ++i) {
        printf(" %d", v[i].second);
      }
    } else {
      for (int i = 0; i < k; ++i) {
        printf(" %d", v[i].second);
        --v[i].first;
      }
    }
    puts("");
    fflush(stdout);
    int x;
    scanf("%d", &x);
    res ^= x;
  }
  printf("! %d\n", res);
  fflush(stdout);
}

int main() {
  int T = 1;
  // scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}