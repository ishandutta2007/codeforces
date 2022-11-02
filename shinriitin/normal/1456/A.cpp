#include <bits/stdc++.h>

constexpr int max_N = 100000 + 21;

int n, p, k, x, y, cnt[2][max_N];

char a[max_N];

void TestCase() {
  scanf("%d%d%d%s", &n, &p, &k, a + 1);
  for (int i = 0; i < k; ++i) {
    cnt[0][i] = cnt[1][i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    int q = i % k;
    cnt[0][q] += a[i] == '0';
    if (i < p) {
      cnt[1][q] += a[i] == '0';
    }
  }
  scanf("%d%d", &x, &y);
  long long ans = LLONG_MAX;
  for (int i = 1; i + p - 1 <= n; ++i) {
    int q = (i + p - 1) % k;
    long long cost = 1LL * (i - 1) * y + 1LL * (cnt[0][q] - cnt[1][q]) * x;
    ans = std::min(ans, cost);
    int q1 = i % k;
    cnt[0][q1] -= a[i] == '0';
    cnt[1][q1] -= a[i] == '0';
    int q2 = (i + p - 1) % k;
    cnt[1][q2] += a[i + p - 1] == '0';
  }
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    TestCase();
  }
}