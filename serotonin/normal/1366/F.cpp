#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005, mod = 1e9+7;

typedef pair <int,int> pii;
#define x first
#define y second

int n, m, q, edges[sz], loss[sz], dis[sz];
vector <pii> g[sz];

void dijk(int id)
{
   dis[1] = 0;
   for(int i=2; i<=n; i++) dis[i] = INT_MAX;

   priority_queue <pii, vector <pii>, greater <pii> > pq;
   pq.push({0, 1});
   while(!pq.empty()) {
      int u = pq.top().y, x = pq.top().x;
      pq.pop();

      if(dis[u] ^ x) continue;

      for(auto p : g[u]) {
         int v = p.x, y = edges[id] - p.y;
         if(y <= 0) {
            loss[id] = x;
            return;
         }
         if(x+y < dis[v]) {
            dis[v] = x+y;
            pq.push({dis[v], v});
         }
      }
   }
}

inline ll fnc(int i, int j) {
   return 1LL * i * edges[j] - loss[j];
}

inline ll sqsum(int n) {
   return (n * (n+1LL) >> 1) % mod;
}

int main()
{
   cin >> n >> m >> q;
   for(int i=1; i<=m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
      edges[i] = w;
   }

   for(int i=1; i<=m; i++) dijk(i);

   ll ans = 0;
   for(int i=1; i<=q; i++) {
      int who = 1;
      for(int j=2; j<=m; j++) if(fnc(i, j) > fnc(i, who)) who = j;

      int lo = i, hi = q;
      while(lo < hi) {
         int md = lo+hi+1 >> 1;
         bool yes = 1;
         for(int j=1; j<=m; j++) if(fnc(md, j) > fnc(md, who)) yes = 0;
         if(yes) lo = md;
         else hi = md - 1;
      }

      ans += (sqsum(lo) - sqsum(i-1)) * edges[who] % mod;
      ans -= 1LL * (lo - (i-1)) * loss[who] % mod;
      ans %= mod;
      i = lo;
   }
   if(ans < 0) ans += mod;
   cout << ans;
}