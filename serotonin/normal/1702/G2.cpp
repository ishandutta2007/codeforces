#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5, lg = 18;

int dep[sz], prnt[sz], spar[lg+1][sz];
vector <int> g[sz];

void deep(int u = 1, int p = -1, int lvl = 1) {
   prnt[u] = p, dep[u] = lvl;
   for(int v : g[u]) if(v ^ p) deep(v, u, lvl + 1);
}

void table(int n) {
   deep();
   memset(spar, -1, sizeof(spar));
   for(int i=1; i<=n; i++) spar[0][i] = prnt[i];
   for(int j=1; (1<<j) < n; j++)
      for(int i=1; i<=n; i++) if(spar[j-1][i] > 0)
            spar[j][i] = spar[j-1][spar[j-1][i]];
}

int getLCA(int x, int y) {
   if(dep[x] < dep[y]) swap(x, y);
   for(int j=lg; j>=0; j--) {
      if(dep[x] - (1<<j) >= dep[y]) x = spar[j][x];
   }
   if(x == y) return x;
   for(int j=lg; j>=0; j--) {
      if(spar[j][x] ^ spar[j][y]) x = spar[j][x], y = spar[j][y];
   }
   return spar[0][x];
}

int getdist(int x, int y) {
   return dep[x] + dep[y] - 2 * dep[getLCA(x, y)];
}

int goup(int x, int z) {
   assert(z >= 0);
   if(!z) return x;
   for(int j=lg; j>=0; j--) {
      int k = 1<<j;
      if(k <= z) {
         x = spar[j][x];
         z -= k;
      }
   }
   return x;
}

int a[sz], side[sz];

bool ok(vector <int> &ara) {
   sort(ara.begin(), ara.end(), [] (int x, int y) {
      return dep[x] > dep[y];
   });
   for(int i=1; i<ara.size(); i++) {
      if(getLCA(ara[i-1], ara[i]) != ara[i]) return 0;
   }
   return 1;
}

int main() {
   int n; cin >> n;
   for(int i=1; i<n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
   }
   table(n);

   int q; cin >> q;
   while(q--) {
      int k;
      scanf("%d", &k);
      for(int i=0; i<k; i++) scanf("%d", &a[i]);
      if(k <= 2) {
         puts("YES");
         continue;
      }

      int lca = a[0];
      for(int i=1; i<k; i++) lca = getLCA(lca, a[i]);

      set <int> st;
      for(int i=0; i<k; i++) {
         if(a[i] == lca) continue;
         int dd = dep[a[i]] - dep[lca] - 1;
         st.insert(side[i] = goup(a[i], dd));
      }
      if(st.size() > 2) {
         puts("NO");
         continue;
      }

      if(st.size() == 1) {
         vector <int> ara(a, a + k);
         puts(ok(ara) ? "YES" : "NO");
      }
      else {
         vector <int> ara, brb;
         for(int i=0; i<k; i++) if(a[i] != lca) {
            if(side[i] == *st.begin()) ara.push_back(a[i]);
            else brb.push_back(a[i]);
         }
         if(ok(ara) and ok(brb)) puts("YES");
         else puts("NO");
      }
   }
}