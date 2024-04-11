#include <bits/stdc++.h>
using namespace std;
#define N 111

int n, x[N], y[N], color;
bool vis[N];
vector <int> v[N];

void dfs(int x) {
  vis[x] = 1;
  for (int i = 0; i < v[x].size(); i ++) if (!vis[v[x][i]]) dfs(v[x][i]);
}

int main() {
//  freopen("c.in", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++) scanf("%d %d", &x[i], &y[i]);
  for (int i = 1; i <= n; i ++) {
    for (int j = 1; j <= n; j ++) if (i != j) {
      if (x[i] == x[j] || y[i] == y[j]) v[i].push_back(j);
    }
  }
  for (int i = 1; i <= n; i ++) if (!vis[i]) color ++, dfs(i);
  printf("%d\n", color - 1);
}