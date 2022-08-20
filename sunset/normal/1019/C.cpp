#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<vector<int>> adj(n), rev(n);
  vector<bool> visit(n), choose(n);
  int answer = 0;
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x].push_back(y);
    rev[y].push_back(x);
  }
  function<void(int)> dfs = [&](int x) {
    if (x == n) {
      return;
    }
    if (visit[x]) {
      dfs(x + 1);
    } else {
      visit[x] = true;
      for (auto y : adj[x]) {
        visit[y] = true;
      }
      dfs(x + 1);
      bool have = false;
      for (auto y : rev[x]) {
        if (choose[y]) {
          have = true;
        }
      }
      if (!have) {
        choose[x] = true;
        ++answer;
      }
    }
  };
  dfs(0);
  printf("%d\n", answer);
  for (int i = 0; i < n; ++i) {
    if (choose[i]) {
      printf("%d", i + 1);
      if (!--answer) {
        putchar(10);
      } else {
        putchar(32);
      }
    }
  }
  return 0;
}