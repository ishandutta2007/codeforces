#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

vector <pair<int,int>> g[sz], rg[sz];
ll dis[sz][2];

int main() {
   int n, m;
   scanf("%d %d", &n, &m);
   while(m--) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      g[u].emplace_back(v, w);
      rg[v].emplace_back(u, w);
   }

   priority_queue <tuple<ll,int,int>> pq;
   pq.emplace(0, 1, 0);
   for(int i=1; i<=n; i++) 
      for(int j=0; j<2; j++) dis[i][j] = LLONG_MAX;
   dis[1][0] = 0;
   
   while(!pq.empty()) {
      auto [x, u, j] = pq.top(); pq.pop();
      x = -x;
      if(dis[u][j] ^ x) continue;

      if(!j) {
         for(auto &[v, w] : g[u]) {
            ll now = x + w;
            if(now < dis[v][0]) {
               dis[v][0] = now;
               pq.emplace(-now, v, 0);
            }
         }
      }

      for(auto &[v, w] : rg[u]) {
         ll now = x + w;
         if(now < dis[v][1]) {
            dis[v][1] = now;
            pq.emplace(-now, v, 1);
         }
      }
   }

   for(int i=2; i<=n; i++) {
      ll ans = min(dis[i][0], dis[i][1]);
      if(ans == LLONG_MAX) printf("-1 ");
      else printf("%lld ", ans);
   }
}