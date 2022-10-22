#include <bits/stdc++.h>

int main() {
  int T, N, M, H;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &N, &M, &H);
    std::vector<std::pair<int, int>> a(N);
    std::vector<int> res(N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", &a[i].first);
      a[i].second = i;
    }
    sort(a.begin(), a.end());
    std::reverse(a.begin(), a.end());
    std::priority_queue<std::pair<int, int>> Q;
    for (int i = 0; i < M; ++i) {
      Q.push(std::make_pair(0, i));
    }
    for (int i = 0; i < N; ++i) {
      auto it = Q.top();
      Q.pop();
      res[a[i].second] = it.second;
      Q.push(std::make_pair(it.first - a[i].first, it.second));
    }
    puts("YES");
    for (int i = 0; i < N; ++i) {
      printf("%d%c", res[i] + 1, " \n"[i + 1 == N]);
    }
  }
}