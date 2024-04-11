#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m, limit;
  scanf("%d %d %d", &n, &m, &limit);
  vector<int> u(m), v(m), degree(n);
  vector<vector<pair<int, int>>> adj(n);
  vector<bool> visit(m);
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &u[i], &v[i]);
    --u[i];
    --v[i];
    adj[u[i]].emplace_back(v[i], i);
    adj[v[i]].emplace_back(u[i], i);
  }
  vector<int> answer(m);
  queue<int> q;
  int current = n;
  for (int i = 0; i < n; ++i) {
    degree[i] = adj[i].size();
    if (degree[i] < limit) {
      q.push(i);
      --current;
    }
  }
  for (int i = m - 1; ~i; --i) {
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      for (auto e : adj[x]) {
        if (!visit[e.second]) {
          visit[e.second] = true;
          if (degree[e.first]-- == limit) {
            q.push(e.first);
            --current;
          }
        }
      }
    }
    answer[i] = current;
    if (!visit[i]) {
      visit[i] = true;
      if (degree[u[i]]-- == limit) {
        q.push(u[i]);
        --current;
      }
      if (degree[v[i]]-- == limit) {
        q.push(v[i]);
        --current;
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    printf("%d\n", answer[i]);
  }
  return 0;
}