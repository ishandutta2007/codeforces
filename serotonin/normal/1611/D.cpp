#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int n, par[sz], wt[sz], a[sz], k, beg[sz], fin[sz], bit[sz], ans[sz];
vector <int> g[sz];

void add(int x) {
   while(x <= n) {
      bit[x]++;
      x += x & -x;
   }
}

int quer(int x) {
   int cnt = 0;
   while(x) {
      cnt += bit[x];
      x -= x & -x;
   }
   return cnt;
}

void dfs(int u) {
   beg[u] = ++k;
   for(int v : g[u]) dfs(v);
   fin[u] = k;
}

void solve() {
   int rt;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) bit[i] = 0, g[i].clear();
   for(int i=1, j; i<=n; i++) {
      scanf("%d", &j); par[i] = j;
      if(i == j) rt = j;
      else g[j].push_back(i);
   }
   k = 0;
   dfs(rt);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=1; i<=n; i++) {
      int u = a[i];
      int has = quer(fin[u]) - quer(beg[u]);
      if(has) {
         puts("-1");
         return;
      }
      add(beg[u]);
      if(i == 1) ans[u] = wt[u] = 0;
      else {
         int pwt = wt[par[u]];
         ans[u] = i - pwt;
         wt[u] = i;
      }
   }

   for(int i=1; i<=n; i++) printf("%d ", ans[i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}