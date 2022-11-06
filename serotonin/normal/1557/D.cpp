#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 6e5+5;

typedef pair <int,int> pii;
#define x first
#define y second

int to[sz], res[sz];
vector <pii> g[sz];
bool ok[sz];

struct segtree {
   int n, h;
   pii tree[sz<<1], ex[sz];

   void renew(int nn) {
      n = nn, h = 32 - __builtin_clz(n);
      memset(ex, 0, sizeof ex);
      memset(tree, 0, sizeof tree);
   }

   inline void apply(int p, pii v) {
      tree[p] = max(tree[p], v);
      if(p < n) ex[p] = max(ex[p], v);
   }

   inline void pull(int p) {
      while(p > 1)
         p >>= 1, tree[p] = max({tree[p<<1], tree[p<<1|1], ex[p]});
   }

   void push(int p) {
      for(int s=h; s; s--) {
         int i = p >> s;
         if(ex[i].x) {
            apply(i<<1, ex[i]);
            apply(i<<1|1, ex[i]);
            ex[i] = {0, 0};
         }
      }
   }

   void update(int l, int r, pii v) {
      if(l > r) return;
      l += n, r += n + 1;
      int l0 = l, r0 = r;
      while(l < r) {
         if(l & 1) apply(l++, v);
         if(r & 1) apply(--r, v);
         l >>= 1, r >>= 1;
      }
      pull(l0), pull(r0 - 1);
   }

   pii query(int l, int r) {
      l += n, r += n + 1;
      push(l), push(r - 1);
      pii res = {0, 0};
      while(l < r) {
         if(l & 1) res = max(res, tree[l++]);
         if(r & 1) res = max(tree[--r], res);
         l >>= 1, r >>= 1;
      }
      return res;
   }
} sgt;

int main() {
   int n, m;
   cin >> n >> m;
   vector <int> a;
   while(m--) {
      int i, x, y;
      scanf("%d %d %d", &i, &x, &y);
      g[i].emplace_back(x, y);
      a.push_back(x);
      a.push_back(y);
   }
   sort(a.begin(), a.end());
   a.erase(unique(a.begin(), a.end()), a.end());
   int z = a.size();
   sgt.renew(z);

   int ans = 0;
   for(int i=n; i; i--) {
      pii now = {0, 0};
      for(auto &[x, y] : g[i]) {
         x = lower_bound(a.begin(), a.end(), x) - a.begin();
         y = lower_bound(a.begin(), a.end(), y) - a.begin();
         now = max(now, sgt.query(x, y));
      }
      now.x++;
      ans = max(ans, now.x);
      to[i] = now.y; res[i] = now.x; now.y = i;
      for(auto &[x, y] : g[i]) sgt.update(x, y, now);
   }

   printf("%d\n", n - ans);
   for(int i=1; i<=n; i++) {
      if(res[i] == ans) {
         ok[i] = 1;
         int j = i;
         while(to[j]) {
            j = to[j];
            ok[j] = 1;
         }
         break;
      }
   }
   for(int i=1; i<=n; i++) if(!ok[i]) printf("%d ", i);
}