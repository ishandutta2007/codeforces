#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz], b[sz], w[sz], ans[sz];
bool done[sz], res[sz];
vector <int> g[sz];

int main() {
   int n, q;
   cin >> n >> q;
   for(int i=0; i<q; i++) scanf("%d %d %d", &a[i], &b[i], &w[i]);

   for(int j=0; j<30; j++) {
      memset(done, 0, sizeof done);
      for(int i=1; i<=n; i++) g[i].clear();

      for(int i=0; i<q; i++) {
         int u = a[i], v = b[i];
         int x = w[i] >> j & 1;
         if(u == v) {
            res[u] = x;
            done[u] = 1;
         }
         else if(!x) {
            res[u] = res[v] = 0;
            done[u] = done[v] = 1;
         }
         else {
            g[u].push_back(v);
            g[v].push_back(u);
         }
      }

      for(int i=1; i<=n; i++) if(!done[i]) {
         res[i] = 0;
         for(int j : g[i]) {
            if(done[j] and !res[j]) res[i] = 1;
         }
         done[i] = 1;
      }

      for(int i=1; i<=n; i++) ans[i] |= res[i] << j;
   }

   for(int i=1; i<=n; i++) printf("%d ", ans[i]);
}