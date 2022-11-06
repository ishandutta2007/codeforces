#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz], xsub[sz];
vector <int> g[sz];

void go(int u, int p) {
   xsub[u] = a[u];
   for(int v : g[u]) if(v ^ p) {
      go(v, u);
      xsub[u] ^= xsub[v];
   }
}

void dfs(int u, int p) {
   for(int v : g[u]) if(v ^ p) {
      dfs(v, u);
      a[u] += a[v];
   }
}

void solve() {
   int n, k, z = 0;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) g[i].clear();
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), z ^= a[i];
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   k--;

   if(z) {
      if(k == 1) puts("NO");
      else {
         go(1, 0);
         for(int i=1; i<=n; i++) a[i] = xsub[i] == z;
         dfs(1, 0);

         int fx = 0;
         for(int i=2; i<=n; i++) if(a[i] == 1 and xsub[i] == z) fx++;

         int zx = 0;
         for(int i=2; i<=n; i++) if(!xsub[i] and a[i]) zx++;

         if(fx >= 2 or zx) puts("YES");
         else puts("NO");
      }
   }
   else puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}