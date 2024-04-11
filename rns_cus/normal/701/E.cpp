#include <bits/stdc++.h>
using namespace std;

const int M = 400001;

int vis[M], f[M];
long long ans;
vector<int> v[M];
int n;

void DFS(int u) {
   vis[u] = 1;
   for(int i = 0; i < v[u].size(); i ++) {
      int x = v[u][i];
      if(vis[x]) continue;
      DFS(x);
      f[u] += f[x];
   }
}

void dfs(int u) {
   vis[u] = 1;
   for(int i = 0; i < v[u].size(); i ++) {
      int x = v[u][i];
      if(vis[x]) continue;
      dfs(x);
      int a = f[x], b = f[1] - f[x];
      ///printf("x = %d a = %d b = %d\n", x, a, b);
      ans += min(a, b);
   }
}


int main() {
   ///freopen("1.in", "r", stdin);
   int k;
   scanf("%d %d", &n, &k);
   for(int i = 1; i <= 2 * k; i ++) {
      int x;
      scanf("%d", &x);
      f[x] ++;
   }
   for(int i = 1; i < n; i ++) {
      int x, y;
      scanf("%d %d", &x, &y);
      v[x].push_back(y);
      v[y].push_back(x);
   }
   DFS(1);
   memset(vis, 0, sizeof(vis));
   ///for(int i = 1; i <= n; i ++) printf("%d ", f[i]); puts("");
   ans = 0;
   dfs(1);
   printf("%I64d\n", ans);
}