#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 3e5+5, inf = 1e18;

typedef pair <int,int> pii;
#define x first
#define y second

vector <pii> g[sz];
ll dis[sz][4];

int main() {
   int n, m;
   scanf("%d %d", &n, &m);
   while(m--) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
   }

   priority_queue <pair<ll,pii>> pq;
   for(int i=1; i<=n; i++) {
      for(int j=0; j<4; j++) dis[i][j] = inf;
   }
   dis[1][0] = 0;
   pq.emplace(0, make_pair(1, 0));

   while(!pq.empty()) {
      auto [x, d] = pq.top(); pq.pop();
      auto [u, f] = d;
      x = -x;

      if(dis[u][f] ^ x) continue;

      for(auto p : g[u]) {
         int v = p.x; ll y = p.y;
         for(int j=0; j<4; j++) {
            if(j & f) continue;
            ll now = x + y;
            if(j & 1) now -= y;
            if(j & 2) now += y;
            if(now < dis[v][j | f]) {
               pq.emplace(-now, make_pair(v, j | f));
               dis[v][j | f] = now;
            }
         }
      }
   }
   for(int i=2; i<=n; i++) printf("%lld ", dis[i][3]);
}