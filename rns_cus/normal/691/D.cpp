#include <bits/stdc++.h>
using namespace std;
#define M 1000010

int p[M], id[M], vis[M], n, m;
vector <int> v[M];
set <int> s[M];

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[x].push_back(y);
    v[y].push_back(x);
  }
  m = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    vis[i] = 1;
    id[i] = ++m;

    s[m].insert(p[i]);

    queue <int> q;
    q.push(i);
    while (!q.empty()) {
      int x = q.front(); q.pop();
      for (int j = 0; j < v[x].size(); j++) {
        int u = v[x][j];
        if (vis[u]) continue;
        id[u] = m; s[m].insert(p[u]);
        vis[u] = 1; q.push(u);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    int x = id[i];
    printf("%d ", *--s[x].end());
    s[x].erase((--s[x].end()));
  }
  puts("");
}