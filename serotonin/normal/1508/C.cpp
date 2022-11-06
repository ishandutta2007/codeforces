#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5, msz = 669, inf = 2e9;

int n, m, rox;
set <int> ndone;
vector <pair<int,int>> g[sz], tree[sz];
bool vis[sz], vg[msz][msz], cant[msz][msz];
priority_queue <tuple<int,int,int>> pq;
int dep[sz], prnt[sz], spar[19][sz], cum[sz];

void add(int u) {
   if(vis[u]) return;
   vis[u] = 1; ndone.erase(u);
   g[u].emplace_back(0, 0);
   g[u].emplace_back(n+1, 0);
   sort(g[u].begin(), g[u].end());
   for(int i=1; i<g[u].size(); i++) {
      vector <int> cut;
      auto [v, w] = g[u][i];
      auto it = ndone.upper_bound(g[u][i-1].first);
      while(it != ndone.end() and *it < v) cut.push_back(*it), it = ndone.erase(it);
      for(int x : cut) {
         tree[u].emplace_back(x, 1);
         tree[x].emplace_back(u, 1);
         add(x);
      }
      if(w) pq.emplace(-w, u, v);
   }
   g[u].pop_back();
}

ll mst() {
   for(int i=1; i<=n; i++) vis[i] = 0, ndone.insert(i);
   add(1);
   ll sum = 0;
   while(!ndone.empty()) {
      auto [w, u, v] = pq.top(); pq.pop();
      if(vis[u] and vis[v]) continue;
      sum -= w;
      add(u), add(v);
      tree[u].emplace_back(v, 0);
      tree[v].emplace_back(u, 0);
      if(u < msz and v < msz) cant[u][v] = cant[v][u] = 1;
   }
   return sum;
}

bool dfs(int u, int p) {
   vis[u] = 1;
   for(auto &[v, w] : g[u]) vg[u][v] = 1;
   for(int v=1; v<=n; v++) if(v ^ p and v ^ u and !vg[u][v]) {
      if(vis[v] or dfs(v, u)) return 1;
   }
   return 0;
}

void deep(int u = 1, int p = -1, int lvl = 1, int d = 0) {
   prnt[u] = p, dep[u] = lvl, cum[u] = d;
   for(auto &[v, w] : tree[u]) if(v ^ p) deep(v, u, lvl + 1, d + w);
}

void table() {
   deep();
   memset(spar, -1, sizeof(spar));
   for(int i=1; i<=n; i++) spar[0][i] = prnt[i];
   for(int j=1; (1<<j) < n; j++)
      for(int i=1; i<=n; i++) if(spar[j-1][i] > 0)
            spar[j][i] = spar[j-1][spar[j-1][i]];
}

int getLCA(int x, int y) {
   if(dep[x] < dep[y]) swap(x, y);
   for(int j=17; j>=0; j--) {
      if(dep[x] - (1<<j) >= dep[y]) x = spar[j][x];
   }
   if(x == y) return x;
   for(int j=17; j>=0; j--) {
      if(spar[j][x] ^ spar[j][y]) x = spar[j][x], y = spar[j][y];
   }
   return spar[0][x];
}

int dis(int x, int y) {
   return cum[x] + cum[y] - 2 * cum[getLCA(x, y)];
}

int main() {
   cin >> n >> m;
   for(int i=0; i<m; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      g[u].emplace_back(v, w);
      g[v].emplace_back(u, w);
      rox ^= w;
   }

   ll xe = n * (n - 1LL) / 2 - m, ans = mst();
   if(xe > n - 1 or !rox) {
      cout << ans;
      return 0;
   }

   for(int i=1; i<=n; i++) if(!vis[i] and dfs(i, 0)) {
      cout << ans;
      return 0;
   }

   table();
   for(int i=1; i<=n; i++) {
      for(auto &[j, w] : g[i]) {
         if(j and !cant[i][j] and dis(i, j)) rox = min(rox, w);
      }
   }
   cout << ans + rox;
}