#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5, rt = 555;

int a[sz], cnt[sz], cc[sz], ans[sz], now;

struct dtt {
   int l, r, id;
} quers[sz];

bool cmp(dtt a, dtt b) {
   if(a.l / rt != b.l / rt) return a.l < b.l;
   return a.r < b.r;
}

inline void add(int x) {
   int &w = cnt[a[x]];
   cc[w]--; w++; cc[w]++;
   w > now ? now++ : 1;
}

inline void del(int x) {
   int &w = cnt[a[x]];
   cc[w]--; w--; cc[w]++;
   !cc[now] ? now-- : 1;
}

int main() {
   int n, q;
   scanf("%d %d", &n, &q);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   for(int i=0; i<q; i++) {
      int x, y;
      scanf("%d %d", &x, &y);
      quers[i] = {x-1, y-1, i};
   }
   sort(quers, quers+q, cmp);

   for(int i=0, l=0, r=-1; i<q; i++) {
      auto d = quers[i];
      while(l < d.l) del(l++);
      while(d.l < l) add(--l);
      while(r < d.r) add(++r);
      while(d.r < r) del(r--);
      ans[d.id] = max(1, (now << 1) - (r - l + 1));
   }
   for(int i=0; i<q; i++) printf("%d\n", ans[i]);
}