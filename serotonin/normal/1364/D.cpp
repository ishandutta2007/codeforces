#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

int depth[sz], par[sz], cyc = sz, bg, ed;
vector <int> g[sz];
bitset <sz> vis;

void dfs(int u = 1, int f = 1)
{
   depth[u] = f;
   if(f & 1) vis[u] = 1;
   for(int v : g[u]) if(v ^ par[u]) {
      if(depth[v]) {
         int d = f - depth[v] + 1;
         if(1 < d && d < cyc) {
            cyc = d;
            bg = v, ed = u;
         }
      }
      else {
         par[v] = u;
         dfs(v, f + 1);
      }
   }
}

int main()
{
   int n, m, k;
   scanf("%d %d %d", &n, &m, &k);
   while(m--) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
   }

   dfs();

   if(cyc ^ sz) {
      if(cyc > k) {
         puts("1");
         k = k + 1 >> 1;
         while(k--) {
            printf("%d ", ed);
            ed = par[par[ed]];
         }
      }
      else {
         puts("2");
         printf("%d\n%d ", cyc, bg);
         while(ed ^ bg) {
            printf("%d ", ed);
            ed = par[ed];
         }
      }
   }
   else {
      puts("1");
      k = k + 1 >> 1;
      int z = vis.count();
      if(z < n - z) vis.flip();
      for(int i=0, j=0; i<k; i++) printf("%d ", j = vis._Find_next(j));
   }
}