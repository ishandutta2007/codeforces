#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define M 100010

int a[M], n, son[M];
LL mx[M];

vector <int> adj[M], w[M];

int dfs(int x, int pa) {
  son[x] = 1;
  int v = 0;
  for (int i = 0; i < adj[x].size(); i++) {
    int y = adj[x][i];
    if (y == pa) continue;
    mx[y] = max(mx[x] + w[x][i], (LL)w[x][i]);
    v += dfs(y, x); son[x] += son[y];
  }
  if (mx[x] > a[x]) return son[x];
  return v;
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 2; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    adj[x].push_back(i);
    w[x].push_back(y);
    adj[i].push_back(x);
    w[i].push_back(y);
  }
  printf("%d\n", dfs(1, 0));
}