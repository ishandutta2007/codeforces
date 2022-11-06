#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+7;

int n, m, a[sz], b[sz];

int bit[sz];

int quer(int x) {
   int res = 0;
   while(x) {
      res += bit[x];
      x -= x & -x;
   }
   return res;
}

void add(int x) {
   while(x <= n) {
      bit[x]++;
      x += x & -x;
   }
}

struct segtree {
   int n, h, tree[sz<<1], ex[sz];
   const static int inf = INT_MAX;

   void renew(int nn) {
      n = nn, h = 32 - __builtin_clz(n);
      for(int i=0; i<n; i++) tree[n+i] = tree[i], ex[i] = 0;
      for(int i=n-1; i>=0; i--) tree[i] = min(tree[i<<1], tree[i<<1|1]);
   }

   inline void apply(int p, int v) {
      tree[p] += v;
      if(p < n) ex[p] += v;
   }

   inline void pull(int p) {
      while(p > 1)
         p >>= 1, tree[p] = min(tree[p<<1], tree[p<<1|1]) + ex[p];
   }

   void push(int p) {
      for(int s=h; s; s--) {
         int i = p >> s;
         if(ex[i]) {
            apply(i<<1, ex[i]);
            apply(i<<1|1, ex[i]);
            ex[i] = 0;
         }
      }
   }

   void update(int l, int r, int v) {
      l += n, r += n + 1;
      int l0 = l, r0 = r;
      while(l < r) {
         if(l & 1) apply(l++, v);
         if(r & 1) apply(--r, v);
         l >>= 1, r >>= 1;
      }
      pull(l0), pull(r0 - 1);
   }

   int query(int l, int r) {
      l += n, r += n + 1;
      push(l), push(r - 1);
      int res = inf;
      while(l < r) {
         if(l & 1) res = min(res, tree[l++]);
         if(r & 1) res = min(tree[--r], res);
         l >>= 1, r >>= 1;
      }
      return res;
   }
} sgt;

void solve() {
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   for(int i=1; i<=m; i++) scanf("%d", &b[i]);

   ll ans = 0;
   map <int,vector<int>> mp;
   for(int i=1; i<=n; i++) mp[-a[i]].push_back(i), bit[i] = 0;
   for(auto &[v, ara] : mp) {
      for(int &i : ara) ans += quer(i);
      for(int &i : ara) add(i);
   }

   priority_queue <pair<int,int>> pq;
   for(int i=1; i<=n; i++) pq.emplace(-a[i], i);

   for(int i=0; i<=n; i++) sgt.tree[i] = i;
   sgt.renew(n + 1);

   map <int,int> cnt;
   for(int i=1; i<=m; i++) cnt[b[i]]++;

   for(auto &[x, cc] : cnt) {
      // x = b[i]
      vector <int> eq;
      while(!pq.empty()) {
         auto [val, i] = pq.top(); val = -val;
         if(val > x) break; pq.pop();
         sgt.update(i, n, -1);
         if(val == x) eq.push_back(i);
         else sgt.update(0, i - 1, +1);
      }
      ans += (ll) sgt.query(0, n) * cc;
//      for(int i=0; i<=n; i++) printf("%d ", sgt.query(i, i)); puts("");
//      cout << x << " " << sgt.query(0, n + 1) << endl;

      for(int i : eq) sgt.update(0, i - 1, +1);
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}