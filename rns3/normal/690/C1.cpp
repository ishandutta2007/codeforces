#include <bits/stdc++.h>
using namespace std;
#define M 100010
int vis[M], n, m, cnt, T;
vector <int> adj[M];

bool check() {
  ++T;
  queue <int> q;
  q.push(1); vis[1] = T;
  int cnt = 0;
  while (!q.empty()) {
    int x = q.front(); q.pop();
    cnt++;
    for (int i = 0; i < adj[x].size(); i++) {
      int u = adj[x][i];
      if (vis[u] == T) continue;
      vis[u] = T; q.push(u);
    }
  }
  return (cnt == n);
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  if (m != n - 1) return puts("no"), 0;
  int x, y;
  for (int i = 0; i < m; i++) scanf("%d %d", &x, &y), adj[x].push_back(y), adj[y].push_back(x);
  if (check()) puts("yes");
  else puts("no");
}