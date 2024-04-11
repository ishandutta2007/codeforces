#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e5+5;

vector <int> g[sz];
int ans[sz],both[sz];
bool no=0;

void dfs(int u, int f)
{
   if(ans[u]) {
      if(ans[u]!=f) no=1;
      return;
   }
   ans[u]=f;
   for(int i=0; i<g[u].size(); i++) {
      int v=g[u][i];
      if(ans[v]==3) continue;
      if(f==1) dfs(v,2);
      else dfs(v,1);
   }
}

int main()
{
   int n,m;
   cin >> n >> m;
   for(int i=0; i<m; i++) {
      int x,y;
      scanf("%d %d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
   }

   if(!g[1].size()) {
      puts("-1");
      return 0;
   }

   int x=1, y=g[1][0];
   for(int i=0; i<g[x].size(); i++) both[g[x][i]]++;
   for(int i=0; i<g[y].size(); i++) both[g[y][i]]++;

   for(int i=1; i<=n; i++) {
      if(i==x || i==y) continue;
      if(both[i]==2) {
         ans[i]=3;
      }
   }

   memset(both, 0, sizeof both);
   int three=0;
   for(int i=1; i<=n; i++) {
      if(ans[i]==3) {
         three++;
         for(int j=0; j<g[i].size(); j++) {
            int v=g[i][j];
            if(ans[v]==3) {
               puts("-1");
               return 0;
            }
            both[v]++;
         }
      }
   }

   if(!three) {
      puts("-1");
      return 0;
   }

   for(int i=1; i<=n; i++) {
      if(ans[i]!=3 && both[i]<three) {
         puts("-1");
         return 0;
      }
   }

   dfs(1,1);

   if(no) {
      puts("-1");
      return 0;
   }

   for(int i=1; i<=n; i++) {
      if(!ans[i]) {
         puts("-1");
         return 0;
      }
   }

   int one=0;
   memset(both, 0, sizeof both);
   for(int i=1; i<=n; i++) {
      if(ans[i]==1) {
         one++;
         for(int j=0; j<g[i].size(); j++) {
            int v=g[i][j];
            both[v]++;
         }
      }
   }

   for(int i=1; i<=n; i++) {
      if(ans[i]==2 && both[i]<one) {
         puts("-1");
         return 0;
      }
   }

   for(int i=1; i<=n; i++) printf("%d ", ans[i]);
}