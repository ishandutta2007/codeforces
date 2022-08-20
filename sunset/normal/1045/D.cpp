#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n;
  scanf("%d", &n);
  vector<double> prob(n), sum(n);
  for (int i = 0; i < n; ++i) {
    scanf("%lf", &prob[i]);
    prob[i] = 1 - prob[i];
  }
  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  vector<int> parent(n, -1);
  function<void(int)> dfs = [&](int x) {
    for (auto y : adj[x]) {
      if (y != parent[x]) {
        sum[x] += prob[y];
        parent[y] = x;
        dfs(y);
      }
    }
  };
  dfs(0);

  double answer = 0;
  for (int i = 0; i < n; ++i) {
    answer += prob[i] * (1 - sum[i]);
  }

  int m;
  scanf("%d", &m);
  while (m--) {
    int x;
    double delta;
    scanf("%d %lf", &x, &delta);
    delta = 1 - delta - prob[x];
    answer += delta * (1 - sum[x]);
    prob[x] += delta;
    if (x) {
      answer -= prob[parent[x]] * delta;
      sum[parent[x]] += delta;
    }
    printf("%lf\n", answer);
  }
  return 0;
}