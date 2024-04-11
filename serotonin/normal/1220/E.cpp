#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=2e5+5;

ll a[sz];
vector <int> g[sz];
bool vis[sz], wow[sz], done[sz];
ll ans;

bool dfs(int u, int p)
{
   if(vis[u]) return 1;
   else {
      vis[u]=1;
      bool x=0;
      for(int i=0; i<g[u].size(); i++) {
         int v=g[u][i];
         if(v==p) continue;
         x|=dfs(v, u);
      }
      if(x) ans+=a[u], wow[u]=1;
      return x;
   }
}

ll rc(int u)
{
   if(done[u] || wow[u]) return 0;
   done[u]=1;
   ll now=0;
   for(int i=0; i<g[u].size(); i++) {
      now=max(now, rc(g[u][i]));
   }
   return now+a[u];
}

int main()
{
   int n,m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
   while(m--) {
      int x,y;
      scanf("%d %d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
   }

   int s;
   scanf("%d", &s);
   bool ok=dfs(s,-1);

   if(ok) {
      ll ex=0;
      for(int i=1; i<=n; i++) {
         if(wow[i]) {
            for(int j=0; j<g[i].size(); j++) {
               ex=max(ex,rc(g[i][j]));    /* AAARGH FREAKING TYPO */
            }
         }
      }
      printf("%lld\n", ans+ex);
   }
   else {
      printf("%lld\n", rc(s));
   }
}