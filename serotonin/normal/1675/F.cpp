#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

bool mark[sz];
vector <int> g[sz];
int dis[sz], csub[sz], tot;

void dfs(int u, int p) {
   csub[u] = mark[u];
   for(int v : g[u]) if(v ^ p)
      dis[v] = dis[u] + 1, dfs(v, u), csub[u] += csub[v];
}

void go(int u, int p) {
   for(int v : g[u]) if(v ^ p and csub[v])
      tot++, go(v, u);
}

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) g[i].clear(), mark[i] = 0;

   int s, t;
   scanf("%d %d", &s, &t);
   while(k--) {
      int x;
      scanf("%d", &x);
      mark[x] = 1;
   }
   mark[t] = 1;

   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }

   dis[s] = 0;
   dfs(s, 0);
   tot = 0, go(s, 0);
   printf("%d\n", 2 * tot - dis[t]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}