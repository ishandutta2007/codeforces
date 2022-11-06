#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 2e5+5, inf = 1e15;

typedef pair <ll,int> pii;
#define x first
#define y second

vector <pii> g[sz];
ll dis[sz], sid[55][sz];

void dijk(int s, int n) {
   priority_queue <pair<pii,int>> pq;
   for(int i=1; i<=n; i++) {
      dis[i] = inf;
      for(int j=1; j<55; j++) sid[j][i] = inf;
   }
   dis[s] = 0;
   pq.emplace(make_pair(0, 0), s);
   while(!pq.empty()) {
      auto [dd, u] = pq.top(); pq.pop();
      auto [x, z] = dd;
      x = -x, z = -z;
      if(!z) {
         if(dis[u] ^ x) continue;
         for(auto &p : g[u]) {
            int v = p.x, y = p.y;
            if(x < sid[y][v]) {
               sid[y][v] = x;
               pq.emplace(make_pair(-x, -y), v);
            }
         }
      }
      else {
         if(sid[z][u] ^ x) continue;
         for(auto &p : g[u]) {
            int v = p.x, y = p.y + z;
            ll now = x + y * y;
            if(now < dis[v]) {
               dis[v] = now;
               pq.emplace(make_pair(-now, 0), v);
            }
         }
      }
   }
}

int main() {
   int n, m;
   scanf("%d %d", &n, &m);
   while(m--) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
   }
   dijk(1, n);
   for(int i=1; i<=n; i++) {
      if(dis[i] ^ inf) printf("%lld ", dis[i]);
      else printf("-1 ");
   }
}