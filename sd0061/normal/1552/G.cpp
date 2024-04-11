#include <bits/stdc++.h>
using int64 = long long;

const int N = 45;
const int P = (1 << 20) - 1;
int n, K;
int64 mask[N], delta[N][N];
std::vector<int> a[N];
std::unordered_set<int64> ok;

bool dfs(int k, int64 known, int64 num) {
  if (k == K) {
    if (known + 1 != (1LL << n)) {
      return false;
    }
    return ok.count(num);
  }
  int64 should_known = ~known & mask[k];
  int cnt = __builtin_popcountll(should_known);
  int64 nxt_known = known | should_known;
  int one = __builtin_popcountll(num & mask[k]);

  int64 nxt_num = num & ~mask[k];
  for (int i = 0; i <= cnt; ++i) {
    int idx = 0;
    if (!dfs(k + 1, nxt_known, nxt_num | delta[k][one + i])) {
      return false;
    }
  }
  return true;
}

void work() {
  scanf("%d%d", &n, &K);
  for (int i = 0; i < K; ++i) {
    int x;
    scanf("%d", &x);
    a[i].resize(x);
    for (int j = 0; j < x; ++j) {
      scanf("%d", &a[i][j]);
      --a[i][j];
      mask[i] ^= 1LL << a[i][j];
    }
    std::reverse(a[i].begin(), a[i].end());
    for (int j = 0; j < x; ++j) {
      delta[i][j + 1] = delta[i][j] | 1LL << a[i][j];
    }
  }
  if (n == 1) {
    puts("ACCEPTED");
    return;
  }

  for (int i = 0; i <= n; ++i) {
    int64 m = 0;
    for (int j = n - i; j < n; ++j) {
      m |= 1LL << j;
    }
    ok.insert(m);
  }

  puts(dfs(0, 0, 0) ? "ACCEPTED" : "REJECTED");
  // for (int i = 0; i <= K; ++i) {
  //   printf("%d : %d\n", i, h[i].size());
  // }
}

int main() {
  int T = 1;
  while (T--) {
    work();
  }
  return 0;
}