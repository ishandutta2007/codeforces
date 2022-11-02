#include <bits/stdc++.h>

const int max_N = (int) 2e5 + 21;

int n, k, a[max_N];

std::vector<int> A;

bool check(int x, bool odd) {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if ((~cnt & 1) ^ odd) {
      ++cnt;
    } else if (a[i] <= x) {
      ++cnt;
    }
  }
  return cnt >= k;
}

bool check(int x) {
  return check(x, true) || check(x, false);
}

int main() {
  scanf("%d%d", &n, &k);
  A.reserve(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
    A.push_back(a[i]);
  }
  std::sort(A.begin(), A.end());
  A.erase(std::unique(A.begin(), A.end()), A.end());
  int lo = 0, hi = A.size() - 1;
  while (lo < hi) {
    int mi = (lo + hi) >> 1;
    if (check(A[mi])) {
      hi = mi;
    } else {
      lo = mi + 1;
    }
  }
  printf("%d\n", A[lo]);
}