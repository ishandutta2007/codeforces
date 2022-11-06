#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int csub[sz];
vector <int> g[sz];

int fnc(int u) {
   if(g[u].size() < 2) return max(0, csub[u] - 2);
   int x = g[u][0], y = g[u][1];
   return max(fnc(x) + csub[y] - 1, fnc(y) + csub[x] - 1);
}

void dfs(int u, int p) {
   csub[u] = 1;
   g[u].erase(find(g[u].begin(), g[u].end(), p));
   for(int v : g[u]) dfs(v, u), csub[u] += csub[v];
}

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) g[i].clear();
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   g[1].push_back(0);
   dfs(1, 0);
   printf("%d\n", fnc(1));
}

int main() {
   int t; 
   cin >> t;
   while(t--) solve();
}