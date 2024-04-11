#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int when[sz], now, eu[sz], ev[sz];

struct dsu {
   int id[sz];
   set <int> g[sz];

   void init(int n) {
      for(int i=1; i<=n; i++) id[i] = i, g[i].clear(), g[i].insert(i);
   }

   void unite(int x, int y) {
      x = id[x], y = id[y];
      if(x == y) return;
      if(g[x].size() < g[y].size()) swap(x, y);

      for(int v : g[y]) {
         if(g[x].count(v - 1)) when[v - 1] = now;
         if(g[x].count(v + 1)) when[v] = now;
         id[v] = x;
      }
      for(int v : g[y]) g[x].insert(v);
      g[y].clear();
   }
} mst;

struct segtree {
   int n, h, tree[sz<<1];

   void renew(int nn) {
      n = nn, h = 32 - __builtin_clz(n);
      for(int i=0; i<n; i++) tree[n+i] = tree[i];
      for(int i=n-1; i>=0; i--) tree[i] = max(tree[i<<1], tree[i<<1|1]);
   }

   int query(int l, int r) {
      l += n, r += n + 1;
      int res = 0;
      while(l < r) {
         if(l & 1) res = max(res, tree[l++]);
         if(r & 1) res = max(tree[--r], res);
         l >>= 1, r >>= 1;
      }
      return res;
   }
} sgt;

void solve() {
   int n, m, q;
   cin >> n >> m >> q;
   for(int i=1; i<=m; i++) scanf("%d %d", &eu[i], &ev[i]);

   mst.init(n);
   for(int i=1; i<=m; i++) {
      now = i;
      mst.unite(eu[i], ev[i]);
   }

   for(int i=1; i<n; i++) sgt.tree[i-1] = when[i];
   sgt.renew(n - 1);

   while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      if(l == r) printf("0 ");
      else printf("%d ", sgt.query(l - 1, r - 2));
   }
   puts("");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}