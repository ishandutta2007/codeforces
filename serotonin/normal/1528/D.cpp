#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 606, inf = 2e9;

int g[sz][sz];
ll ans[sz];
bool done[sz];

int main() {
   int n, m;
   cin >> n >> m;
   while(m--) {
      int u, v, c;
      scanf("%d %d %d", &u, &v, &c);
      u++, v++;
      g[u][v] = c;
   }

   ans[0] = inf;
   for(int i=1; i<=n; i++) g[i][0] = inf;

   for(int s=1; s<=n; s++) {
      for(int i=1; i<=n; i++) ans[i] = inf, done[i] = 0;
      ans[s] = 0;

      for(int i=1; i<=n; i++) {
         int u = 0;
         for(int j=1; j<=n; j++) {
            if(!done[j] and ans[j] < ans[u]) u = j;
         }
         done[u] = 1;
         ll t = ans[u];

         int wv = 0;
         for(int v=1; v<=n; v++) if(g[u][v] and g[u][v] < g[u][wv]) wv = v;

         int d = g[u][wv], v = wv + t % n;
         if(v > n) v -= n;
         swap(wv, v);

         for(int j=0; j<n; j++) {
            ans[wv] = min(ans[wv], t + d);
            wv++, v++, d++;
            if(v > n) v = 1;
            if(wv > n) wv = 1;
            if(g[u][v] and g[u][v] < d) d = g[u][v];
         }
      }

      for(int i=1; i<=n; i++) printf("%lld ", ans[i]);
      puts("");
   }
}