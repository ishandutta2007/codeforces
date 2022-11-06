#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int n, a[sz], ans;
ll bit[sz];

ll quer(int x) {
   ll res = 0;
   while(x) {
      res += bit[x];
      x -= x & -x;
   }
   return res;
}

void add(int x, int v) {
   ans++;
   while(x <= n) {
      bit[x] += v;
      x += x & -x;
   }
}

struct segtree {
   int n, h;
   ll tree[sz<<1], ex[sz];

   void renew(int nn) {
      n = nn, h = 32 - __builtin_clz(n);
      for(int i=0; i<n; i++) tree[n+i] = tree[i], ex[i] = 0;
      for(int i=n-1; i>=0; i--) tree[i] = min(tree[i<<1], tree[i<<1|1]);
   }

   inline void apply(int p, ll v) {
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

   void update(int l, int r, ll v) {
      l += n, r += n + 1;
      int l0 = l, r0 = r;
      while(l < r) {
         if(l & 1) apply(l++, v);
         if(r & 1) apply(--r, v);
         l >>= 1, r >>= 1;
      }
      pull(l0), pull(r0 - 1);
   }

   ll query(int l, int r) {
      l += n, r += n + 1;
      push(l), push(r - 1);
      ll res = LLONG_MAX;
      while(l < r) {
         if(l & 1) res = min(res, tree[l++]);
         if(r & 1) res = min(tree[--r], res);
         l >>= 1, r >>= 1;
      }
      return res;
   }
} sgt;

int main() {
   cin >> n;
   vector <pair<int,int>> neg;
   for(int i=1; i<=n; i++) {
      scanf("%d", &a[i]);
      if(a[i] < 0) neg.emplace_back(a[i], i);
      else add(i, a[i]);
   }
   for(int i=1; i<=n; i++) sgt.tree[i-1] = quer(i);
   sgt.renew(n);

   sort(neg.begin(), neg.end());
   reverse(neg.begin(), neg.end());

   for(auto &[v, i] : neg) {
      if(quer(i) >= -v and v + sgt.query(i-1, n-1) >= 0) {
         add(i, v);
         sgt.update(i-1, n-1, v);
      }
   }
   cout << ans;
}