#include <bits/stdc++.h>
 
const int N = 100000;
const int K = 8;
 
int n, m, k, indices[K], dp[2][1 << K];
std::pair<int, int> events[N << 1];
 
void update(int &x, int a) { x = std::max(x, a); }
 
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n << 1; ++i) {
    scanf("%d", &events[i].first);
    if (~i & 1) {
      events[i].first--;
      events[i].second = n + (i >> 1);
    } else {
      events[i].second = i >> 1;
    }
  }
  std::sort(events, events + (n << 1));
  int size = 0;
  for (int i = 0; i < n << 1; ++i) {
    memset(dp[i + 1 & 1], 0, sizeof(dp[i + 1 & 1]));
    int j = events[i].second;
    if (j < n) {
      j = std::find(indices, indices + size, j) - indices;
      int sub = (1 << j) - 1;
      for (int msk = 0; msk < 1 << size; ++msk) {
        int extras = i && __builtin_parity(msk)
                         ? events[i].first - events[i - 1].first
                         : 0;
        update(dp[i + 1 & 1][(msk & sub) | ((msk >> 1) & ~sub)],
               dp[i & 1][msk] + extras);
      }
      size--;
      memcpy(indices + j, indices + j + 1, sizeof(*indices) * (size - j));
    } else {
      for (int msk = 0; msk < 1 << size; ++msk) {
        int extras = i && __builtin_parity(msk)
                         ? events[i].first - events[i - 1].first
                         : 0;
        update(dp[i + 1 & 1][msk], dp[i & 1][msk] + extras);
        update(dp[i + 1 & 1][msk | 1 << size], dp[i & 1][msk] + extras);
      }
      indices[size++] = j - n;
    }
  }
  printf("%d\n", dp[0][0]);
}