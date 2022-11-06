#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int n, m, bf, tot, ax[sz], par[sz], val[sz], who[sz], ke[sz], rdone[sz];
vector <pair<int,int>> og[sz];
vector <int> g[sz], rg[sz], st;
bool done[sz];

void dfs(int u) {
   done[u] = 1; rdone[u] = 0;
   for(int v : g[u]) if(!done[v]) dfs(v);
   st.push_back(u);
}

void dfs2(int u, int k) {
   rdone[u] = k;
   for(int v : rg[u]) if(!rdone[v]) dfs2(v, k);
}

bool sat() {
   st.clear();
   for(int i=2; i<=tot; i++) if(!done[i]) dfs(i);

   int c = 0;
   reverse(st.begin(), st.end());
   for(int x : st) if(!rdone[x]) dfs2(x, ++c);

   vector <int> ans;
   for(int i=1; i<=bf; i++) {
      int u = i << 1, v = u | 1;
      if(rdone[u] == rdone[v]) return 0;
      if(rdone[u] > rdone[v]) ans.push_back(i);
   }
   for(int x : ans) val[ke[x]] = 1;
   return 1;
}

void add1(int u, int v) {
   g[u].push_back(v);
   rg[v].push_back(u);
}

void go(int u, int p, int x, int last) {
   ax[u] = x, who[u] = last;
   for(auto [v, w] : og[u]) if(v ^ p) {
      if(w >= 0) go(v, u, x ^ w, last);
      else {
         ke[++bf] = v;
         go(v, u, x, bf);
      }
      par[v] = u, val[v] = max(0, w);
   }
}

void trav(int u, int p, int x) {
   for(auto [v, w] : og[u]) if(v ^ p) {
      if(w >= 0) trav(v, u, x);
      else {
         int y = val[v];
         val[v] ^= x;
         trav(v, u, y);
      }
   }
}

void solve() {
   scanf("%d %d", &n, &m);
   tot = n << 1 | 1, bf = 1; ke[1] = 1;
   for(int i=0; i<=tot; i++) done[i] = 0, og[i].clear(), g[i].clear(), rg[i].clear();

   for(int i=1; i<n; i++) {
      int u, v, w;
      scanf("%d %d %d", &u, &v, &w);
      og[u].emplace_back(v, w);
      og[v].emplace_back(u, w);
   }

   go(1, 0, 0, 1);
   tot = bf << 1 | 1;

   add1(2, 3);
   while(m--) {
      int x, y, d;
      scanf("%d %d %d", &x, &y, &d);
      int now = __builtin_popcount(ax[x] ^ ax[y]) & 1;
      x = who[x], y = who[y];
      x <<= 1, y <<= 1;
      if(now == d) x |= 1;
      // printf("%d %d\n", x, y);
      add1(x ^ 1, y);
      add1(y ^ 1, x);
      add1(x, y ^ 1);
      add1(y, x ^ 1);
   }

   if(!sat()) {
      puts("NO");
      return;
   }
   puts("YES");
   trav(1, 0, 0);
   for(int i=2; i<=n; i++) printf("%d %d %d\n", i, par[i], val[i]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}