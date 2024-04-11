#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4005;

int n;
char s[sz][sz];
vector <int> g[sz], ara;
vector <vector<int>> cc;
bool vis[sz];

void dfs(int u) {
   vis[u] = 1;
   ara.push_back(u);
   for(int v : g[u]) if(!vis[v]) dfs(v);
}

int disc[sz], farup[sz], kt, root;
bitset <sz> artp;

void dfs(int u, int p) {
   int child = 0;
   disc[u] = farup[u] = kt++;
   for(int v : g[u]) if(v ^ p) {
      if(disc[v])
         farup[u] = min(farup[u], disc[v]);
      else {
         child++;
         dfs(v, u);
         farup[u] = min(farup[u], farup[v]);

         if(disc[u] <= farup[v] && u ^ root) artp[u] = 1;
      }
   }
   if(u == root && child > 1) artp[u] = 1;
}

void graph() {
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%s", s[i]);
   for(int i=1; i<=n; i++) g[i].clear();
   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         if(s[i][j] == '1') {
            g[i+1].push_back(j+1);
          //g[j+1].push_back(i+1);
         }
      }
   }
   kt = 1;
   for(int i=1; i<=n; i++) disc[i] = farup[i] = artp[i] = 0;
   for(int i=1; i<=n; i++)
      if(!disc[i]) root = i, dfs(i,-1);
}

void solve() {
   graph();
   cc.clear();
   for(int i=1; i<=n; i++) vis[i] = 0;

   for(int i=1; i<=n; i++) if(!vis[i]) {
      ara.clear();
      dfs(i);
      cc.push_back(ara);
   }

   if(cc.size() == 1) {
      puts("0");
      return;
   }

   for(auto &vec : cc) {
      ara = vec;

      int z = ara.size();

      for(int u : ara) if(g[u].size() < z - 1 and !artp[u]) {
         puts("1");
         printf("%d\n", u);
         return;
      }

      if(z == 1) {
         puts("1");
         printf("%d\n", ara[0]);
         return;
      }
   }

   if(cc.size() == 2) {
      if(cc[0].size() > cc[1].size()) swap(cc[0], cc[1]);
      printf("%d\n", cc[0].size());
      for(int u : cc[0]) printf("%d ", u); puts("");
   }
   else {
      puts("2");
      for(auto &vec : cc) {
         if(vec.size() == 2) {
            printf("%d %d\n", vec[0], vec[1]);
            return;
         }
      }
      printf("%d %d\n", cc[0][0], cc[1][0]);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}