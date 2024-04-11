#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  vector<int> size(n, 1);
  vector<int> depth(n);

  long long answer = 0;

  function<void(int, int)> dfs = [&](int x, int parent) {
    for (auto y : adj[x]) {
      if (y != parent) {
        depth[y] = depth[x] + 1;
        dfs(y, x);
        answer += (long long)size[y] * (n - size[y]);
        size[x] += size[y];
      }
    }
  };

  dfs(0, -1);
  int odd = 0;
  for (int i = 0; i < n; ++i) {
    if (depth[i] & 1) {
      ++odd;
    }
  }
  answer += (long long)odd * (n - odd);
  printf("%lld\n", answer >> 1);
  return 0;
}