#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

typedef pair <int, int> pii;
#define x first
#define y second

bool no;
int w[sz], color[sz];
bitset <sz> vis;
vector <int> g[sz], ts;
vector <pii> rest;

void dfs(int u) {
   vis[u] = 1;
   for(int v : g[u]) if(!vis[v]) dfs(v);
   ts.push_back(u);
}

void t_sort(int n) {
   ts.clear();
   for(int i=1; i<=n; i++) if(!vis[i]) dfs(i);
   reverse(ts.begin(), ts.end());
}

void dfs(int u, int p) {
   color[u] = 1;
   for(int v : g[u]) {
      if(no) return;
      if(color[v] == 1) {
         no = 1;
         return;
      }
      if(!color[v]) dfs(v, u);
   }
   color[u] = 2;
}

void cyc(int n) {
   no = 0;
   for(int i=1; i<=n; i++) color[i] = 0;
   for(int i=1; i<=n; i++) if(!color[i]) dfs(i, -1);
}

void solve() {
   int n, m;
   cin >> n >> m;
   rest.clear();
   for(int i=1; i<=n; i++) g[i].clear(), vis[i] = 0;
   while(m--) {
      int f, u, v;
      scanf("%d %d %d", &f, &u, &v);
      if(f) g[u].push_back(v);
      else rest.emplace_back(u, v);
   }

   cyc(n);
   if(no) {
      puts("NO");
      return;
   }

   t_sort(n);
   int k = 0;
   for(int x : ts) w[x] = ++k;

   puts("YES");
   for(int i=1; i<=n; i++) {
      for(int j : g[i]) printf("%d %d\n", i, j);
   }
   for(auto p : rest) {
      int u = p.x, v = p.y;
      if(w[u] > w[v]) printf("%d %d\n", v, u);
      else printf("%d %d\n", u, v);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}