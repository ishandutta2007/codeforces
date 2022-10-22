#include <bits/stdc++.h>
using int64 = long long;
const int N = 200005;

int n, a[N];

void work() {
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    sum ^= a[i];
  }
  if (sum) {
    puts("NO");
    return;
  }
  std::vector<int> res;
  if (n & 1) {
    for (int i = 1; i + 2 <= n; i += 2) {
      res.emplace_back(i);
    }
    for (int i = n - 4; i >= 1; i -= 2) {
      res.emplace_back(i);
    }
  } else {
    bool found = false;
    for (int k = 1; k <= n - 1; k += 2) {
      int la = 0;
      int lb = 0;
      for (int i = 0; i < k; ++i) {
        la ^= a[i];
      }
      if (la == 0) {
        for (int i = 1; i + 2 <= k; i += 2) {
          res.emplace_back(i);
        }
        for (int i = k - 4; i >= 1; i -= 2) {
          res.emplace_back(i);
        }
        n -= k;
        for (int i = 1; i + 2 <= n; i += 2) {
          res.emplace_back(k + i);
        }
        for (int i = n - 4; i >= 1; i -= 2) {
          res.emplace_back(k + i);
        }
        n += k;
        found = true;
        break;
      }
    }
    if (!found) {
      puts("NO");
      return;
    }
  }

  puts("YES");
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); ++i) {
    printf("%d%c", res[i], " \n"[i + 1 == res.size()]);
  }
}

int main() {
  int T = 1;
  scanf("%d", &T);
  while (T--) {
    work();
  }
  return 0;
}