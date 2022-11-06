#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

vector <int> g[sz];

int n, a[sz], heavy[sz], dep[sz], head[sz], par[sz], pos[sz], cpos;
ll ex[sz <<2], tree[sz << 2];

void push(int u, int b, int e) {
   tree[u] += ex[u] * (e - b + 1LL);
   if(b ^ e) ex[u << 1] += ex[u], ex[u << 1 | 1] += ex[u];
   ex[u] = 0;
}

void update(int l, int r, int w, int u = 1, int b = 1, int e = n) {
   if(ex[u]) push(u, b, e);
   if(e < l or r < b or l > r) return;
   if(l <= b and e <= r) {
      ex[u] = w;
      return push(u, b, e);
   }
   int m = b + e >> 1, x = u << 1, y = x + 1;
   update(l, r, w, x, b, m);
   update(l, r, w, y, m+1, e);
   tree[u] = tree[x] + tree[y];
}

ll query(int l, int r, int u = 1, int b = 1, int e = n) {
   if(ex[u]) push(u, b, e);
   if(e < l || r < b || l > r) return 0;
   if(l <= b && e <= r) return tree[u];

   int m = b + e >> 1, x = u << 1, y = x + 1;
   return query(l, r, x, b, m) + query(l, r, y, m+1, e);
}

int dfs(int u = 1) {
   int subc = 1, mxc = 0;
   for(int v : g[u]) if(v ^ par[u]) {
      par[v] = u;
      dep[v] = dep[u] + 1;
      int nxtc = dfs(v);
      subc += nxtc;
      if(nxtc > mxc) mxc = nxtc, heavy[u] = v;
   }
   return subc;
}

void hfs(int u = 1, int h = 1) {
   head[u] = h, pos[u] = ++cpos;
   int hv = heavy[u];
   if(hv) hfs(hv, h);

   for(int v : g[u])
      if(v ^ par[u] and v ^ hv)
         hfs(v, v);
}

void hldup(int u, int v, int c) {
   while(head[u] ^ head[v]) {
      if(dep[head[u]] < dep[head[v]]) swap(u, v);
      update(pos[head[u]], pos[u], c);
      u = par[head[u]];
   }

   if(dep[u] > dep[v]) swap(u, v);
   update(pos[u], pos[v], c);
}

ll hld_query(int u, int v) {
   ll res = 0;
   while(head[u] ^ head[v]) {
      if(dep[head[u]] < dep[head[v]]) swap(u, v);
      res += query(pos[head[u]], pos[u]);
      u = par[head[u]];
   }

   if(dep[u] > dep[v]) swap(u, v);
   return res + query(pos[u], pos[v]);
}

int main() {
   int q;
   cin >> n >> q;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), a[i] = abs(a[i]);

   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }

   dfs();
   hfs();

   for(int i=1; i<=n; i++) hldup(i, i, a[i]);

   while(q--) {
      int t, u, v;
      scanf("%d %d %d", &t, &u, &v);
      if(t == 1) {
         v = abs(v);
         int p = a[u];
         a[u] = v;
         hldup(u, u, v - p);
      }
      else printf("%lld\n", 2 * hld_query(u, v) - a[u] - a[v]);
   }
}