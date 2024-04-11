#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz], b[sz], c[sz], f[sz], upto[sz], ans[sz];
vector <int> g[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), f[i] = upto[i] = 0;
   for(int i=1; i<=n; i++) scanf("%d", &b[i]), g[i].clear();
   for(int i=1; i<=m; i++) scanf("%d", &c[i]);

   for(int i=1; i<=n; i++) {
      if(a[i] ^ b[i]) g[b[i]].push_back(i);
      f[b[i]] = i;
   }

   if(!f[c[m]]) {
      puts("NO");
      return;
   }

   int lp = 0;
   for(int i=m; i; i--) {
      int x = c[i], &j = upto[x];
      if(j < g[x].size()) {
         ans[i] = g[x][j];
         j++;
      }
      else if(lp) ans[i] = lp;
      else ans[i] = f[x];
      lp = ans[i];
   }

   for(int i=1; i<=n; i++) if(upto[i] < g[i].size()) {
      puts("NO");
      return;
   }

   puts("YES");
   for(int i=1; i<=m; i++) printf("%d ", ans[i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}