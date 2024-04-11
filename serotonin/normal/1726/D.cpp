#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int eu[sz], ev[sz], a[sz], tt;
vector <int> g[sz];
vector <pair<int,int>> cyc;
bool vis[sz];

set <int> st;
      
void dfs(int u, int p) {
   vis[u] = 1;
   a[u] = ++tt;
   for(int v : g[u]) if(v - p) {
      if(!vis[v]) dfs(v, u);
      else cyc.emplace_back(u, v);
   }
}

void go(int u, int p, int t) {
   for(int v : g[u]) if(v - p) {
      if(st.count(u) and st.count(v)) continue;
      if(v == t) cyc.emplace_back(min(u, v), max(u, v));
      if(cyc.size() == 3) return;
      go(v, u, t);
   }
}

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   cyc.clear();
   for(int i=1; i<=n; i++) g[i].clear(), vis[i] = 0;
   for(int i=0; i<m; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
      if(u > v) swap(u, v);
      eu[i] = u, ev[i] = v;
   }
   tt = 0;
   dfs(1, 0);

   for(auto &[u, v] : cyc) if(u > v) swap(u, v);
   sort(cyc.begin(), cyc.end());
   cyc.erase(unique(cyc.begin(), cyc.end()), cyc.end());

   if(cyc.size() == 3) {
      st.clear();
      for(auto [u, v] : cyc) st.insert(u), st.insert(v);
      if(st.size() == 3) {
         auto [u, v] = cyc.back();
         cyc.pop_back();
         go(u, 0, v);
      }
   }
   for(int i=0; i<m; i++) {
      int u = eu[i], v = ev[i];
      pair <int,int> pp = {u, v};
      bool yes = 0;
      for(auto p : cyc) if(p == pp) yes = 1;
      if(yes) printf("1");
      else printf("0");
   }
   puts("");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}