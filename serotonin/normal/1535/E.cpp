#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5, lg = 18;

int gold[sz], price[sz], dep[sz], spar[lg+1][sz];
vector <int> g[sz];

int goup(int x, int z) {
   if(!z) return x;
   for(int j=lg; j>=0; j--) {
      int k = 1 << j;
      if(k <= z) {
         x = spar[j][x];
         z -= k;
      }
   }
   return x;
}

void addNode(int i, int p) {
   spar[0][i] = p;
   dep[i] = 1 + dep[p];
   for(int j=1; ; j++) {
      int v = spar[j-1][i];
      if(v < 0) break;
      spar[j][i] = spar[j-1][v];
   }
}

int main() {
   int q;
   cin >> q >> gold[0] >> price[0];
   memset(spar, -1, sizeof(spar));
   for(int i=1; i<=q; i++) {
      int tp;
      scanf("%d", &tp);
      if(tp == 1) {
         int j;
         scanf("%d %d %d", &j, &gold[i], &price[i]);
         addNode(i, j);
      }
      else {
         int u, w;
         scanf("%d %d", &u, &w);

         int r = u;
         for(int j=lg; j>=0; j--) {
            int v = spar[j][r];
            if(v >= 0 and gold[v]) r = v;
         }

         ll ans = 0; int cut = 0;
         int d = dep[u] - dep[r] + 1;
         while(d-- and w) {
            r = goup(u, d);
            int here = min(gold[r], w);
            cut += here;
            gold[r] -= here; w -= here;
            ans += (ll) here * price[r];
         }
         printf("%d %lld\n", cut, ans); fflush(stdout);
      }
   }
}