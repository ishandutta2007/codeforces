#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int kt, a[sz], b[sz], who[sz], ans;
vector <int> g[sz], cg[sz];
set <int> st;

void go(int u) {
   a[u] = ++kt; who[kt] = u;
   for(int v : g[u]) go(v);
   b[u] = kt;
}

void dfs(int u) {
   int p = 0;
   auto it = st.upper_bound(a[u]);
   if(it == st.end() or *it > b[u]) {
      if(it == st.begin() or b[who[*prev(it)]] < a[u]) p = -1;
      else {
         p = *prev(it);
         st.erase(p);
      }
      st.insert(a[u]);
   }
   ans = max(ans, (int)st.size());

   for(int v : cg[u]) dfs(v);

   if(p) {
      st.erase(a[u]);
      if(p > 0) st.insert(p);
   }
}

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) cg[i].clear(), g[i].clear();
   for(int i=2, j; i<=n; i++) {
      scanf("%d", &j);
      cg[j].push_back(i);
   }
   for(int i=2, j; i<=n; i++) {
      scanf("%d", &j);
      g[j].push_back(i);
   }
   kt = 0;
   go(1);

   st.clear();
   ans = 0;
   dfs(1);

   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}