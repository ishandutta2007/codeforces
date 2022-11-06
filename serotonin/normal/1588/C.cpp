#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 3e5+5, inf = 1LL<<50;

typedef pair <ll,int> pii;
#define x first
#define y second

pii operator + (const pii &a, const pii &b) {
   pii p = a;
   if(b.x < p.x) p = b;
   else if(b.x == p.x) p.y += b.y;
   return p;
};

int n, a[sz];
ll val[sz], sum[sz];

struct segtree {
   pii zer[sz<<2];
   ll ex[sz<<2];

   void init(int u = 1, int b = 0, int e = n - 1) {
      ex[u] = 0;
      if(b == e) {
         zer[u] = {sum[e], 1};
         return;
      }
      int m = b + e >> 1, x = u << 1, y = x + 1;
      init(y, m+1, e); init(x, b, m);
      zer[u] = zer[x] + zer[y];
   }

   inline void push(int u, int b, int e) {
      zer[u].x += ex[u];
      if(b ^ e) ex[u << 1] += ex[u], ex[u << 1 | 1] += ex[u];
      ex[u] = 0;
   }

   void update(int l, int r, int w, int u = 1, int b = 0, int e = n - 1) {
      if(ex[u]) push(u, b, e);
      if(e < l or r < b or l > r) return;
      if(l <= b and e <= r) {
         ex[u] = w;
         return push(u, b, e);
      }
      int m = b + e >> 1, x = u << 1, y = x + 1;
      update(l, r, w, x, b, m);
      update(l, r, w, y, m+1, e);
      zer[u] = zer[x] + zer[y];
   }

   pii query(int l, int r, int u = 1, int b = 0, int e = n - 1) {
      if(ex[u]) push(u, b, e);
      if(l <= b and e <= r) return zer[u];
      if(l > e or r < b or l > r) return {inf, 1};
      int m = b + e >> 1, x = u << 1, y = x + 1;
      return query(l, r, x, b, m) + query(l, r, y, m+1, e);
   }

   int zquery(int u = 1, int b = 0, int e = n - 1) {
      if(ex[u]) push(u, b, e);
      if(zer[u].x >= 0) return e + 1;
      if(b == e) return e;
      int m = b + e >> 1, x = u << 1, y = x + 1;
      if(ex[x]) push(x, b, m);
      return zer[x].x < 0 ? zquery(x, b, m) : zquery(y, m+1, e);
   }
} odd, eve;

void solve() {
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   val[0] = a[0];
   for(int i=1; i<n; i++) val[i] = a[i] - val[i-1];

   for(int i=0; i<n; i++) sum[i] = inf;
   for(int i=0; i<n; i+=2) sum[i] = val[i];
   eve.init();
   for(int i=0; i<n; i++) sum[i] = inf;
   for(int i=1; i<n; i+=2) sum[i] = val[i];
   odd.init();

   ll ans = 0;
   for(int i=0; i<n; i++) {
      int j = min(odd.zquery(), eve.zquery()) - 1;
      
      pii qe = eve.query(i, j);
      if(!qe.x) ans += qe.y;
      pii qo = odd.query(i, j);
      if(!qo.x) ans += qo.y;
      
      if(i & 1) {
         odd.update(i, n - 1, -a[i]);
         eve.update(i, n - 1, a[i]);
      }
      else {
         eve.update(i, n - 1, -a[i]);
         odd.update(i, n - 1, a[i]);
      }
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}