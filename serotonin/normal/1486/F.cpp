#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

typedef pair <int,int> pii;
#define x first
#define y second

ll ans;
int n, m, depth[sz], prnt[sz], spar[19][sz];
vector <int> g[sz];

int cnt[sz], plca[sz], dot[sz], up[sz];
vector <pii> mp[sz];

void deep(int u = 1, int p = -1, int lvl = 1) {
   prnt[u] = p, depth[u] = lvl;
   for(int v : g[u]) if(v ^ p) deep(v, u, lvl + 1);
}

void table() {
   deep();
   memset(spar, -1, sizeof(spar));
   for(int i=1; i<=n; i++) spar[0][i] = prnt[i];

   for(int j=1; (1<<j) < n; j++) {
      for(int i=1; i<=n; i++) {
         if(spar[j-1][i] > 0) {
            spar[j][i] = spar[j-1][spar[j-1][i]];
         }
      }
   }
}

int getlca(int x, int y) {
   if(depth[x] < depth[y]) swap(x, y);

   int big = 31 - __builtin_clz(depth[x]);
   for(int j=big; j>=0; j--) {
      if(depth[x] - (1<<j) >= depth[y]) {
         x = spar[j][x];
      }
   }
   if(x == y) return x;

   big = 31 - __builtin_clz(depth[x]);
   for(int j=big; j>=0; j--) {
      if(spar[j][x] ^ spar[j][y]) {
         x = spar[j][x], y = spar[j][y];
      }
   }
   return spar[0][x];
}

int goup(int x, int z) {
   if(z < 0) return 0;
   if(!z) return x;
   int big = 31 - __builtin_clz(z);
   for(int j=big; j>=0; j--) {
      int k = 1<<j;
      if(k <= z) {
         x = spar[j][x];
         z -= k;
      }
   }
   return x;
}

void dfs(int u, int p) {
   for(int v : g[u]) if(v ^ p) {
      dfs(v, u);
      up[u] += up[v];
   }
   sort(mp[u].begin(), mp[u].end());
   for(int i=0, b=u; i<mp[u].size(); i++) {
      auto [a, c] = mp[u][i];
      ll now = cnt[b] - plca[a] - plca[c];
      int z = 1;
      while(i+1 < mp[u].size() and mp[u][i+1] == mp[u][i]) i++, z++;
      if(a) now += z;
      now += (up[b] - up[a] - up[c] + plca[a] + plca[c]) * 2;
      ans += now * z;
   }
   ans += (cnt[u] + up[u]) * 2LL * dot[u];
   ans += dot[u] * (dot[u] - 1LL);
}

int main() {
   cin >> n;
   for(int i=1; i<n; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      g[x].push_back(y);
      g[y].push_back(x);
   }
   table();
   cin >> m;
   for(int i=1; i<=m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      if(u == v) dot[u]++;
      else {
         int lca = getlca(u, v);
         int x = goup(v, depth[v] - depth[lca] - 1);
         int y = goup(u, depth[u] - depth[lca] - 1);
         if(x > y) swap(x, y);
         mp[lca].emplace_back(x, y);
         cnt[lca]++;
         if(x) plca[x]++;
         if(y) plca[y]++;
         up[u]++, up[v]++;
         up[lca] -= 2;
      }
   }
   dfs(1, 0);
   cout << ans / 2;
}