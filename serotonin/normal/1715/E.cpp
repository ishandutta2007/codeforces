#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 1e5+5, inf = 1e17;

struct Line {
   ll m, c, pl = -inf, pr = inf;
   Line() {}
   Line(ll m, ll c) : m(m), c(c) {}
};

struct LineHull : deque <Line> {
   ll isect(Line l, Line r) {
      ll a = r.c - l.c, b = l.m - r.m;
      return a / b - ((a ^ b) < 0 && a % b);
   }

   void add(ll m, ll c) {
      Line r (m, c);
      while(!empty()) {
         r.pl = isect(back(), r);
         if(r.pl > back().pl) break;
         pop_back();
      }
      if(!empty()) back().pr = r.pl;
      push_back(r);
   }

   ll query(ll x) {
      while(!empty() && front().pr < x) pop_front();
      return empty() ? 0 : front().m * x + front().c;
   }
};

vector <pair<int,int>> g[sz];
ll dis[sz];

int main() {
   int n, m, k;
   cin >> n >> m >> k;
   while(m--) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
   }

   priority_queue <pair<ll,int>> pq;
   pq.emplace(0, 1);
   for(int i=2; i<=n; i++) dis[i] = inf;

   for(int j=0; j<=k; j++) {
      while(!pq.empty()) {
         auto [d, u] = pq.top(); pq.pop();
         d = -d;
         if(dis[u] ^ d) continue;
         for(auto &[v, w] : g[u]) {
            ll now = d + w;
            if(now < dis[v]) {
               dis[v] = now;
               pq.emplace(-now, v);
            }
         }
      }
      if(j == k) break;

      LineHull hull;
      for(int i=1; i<=n; i++) {
         ll c = dis[i] + (ll) i * i;
         hull.add(i << 1, -c);
      }

      for(int i=1; i<=n; i++) {
         ll now = (ll) i * i - hull.query(i);
         if(now < dis[i]) dis[i] = now, pq.emplace(-now, i);
      }
   }
   
   for(int i=1; i<=n; i++) printf("%lld ", dis[i]);
}