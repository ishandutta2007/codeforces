#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

bool vis[27], done[27][27];
vector <int> g[27];
char a[sz], b[sz];

void dfs(int u) {
   if(vis[u]) return;
   vis[u] = 1;
   for(int v : g[u]) dfs(v);
}

void solve() {
   int n;
   scanf("%d %s %s", &n, a, b);
   for(int i=0; i<20; i++) g[i].clear();
   memset(done, 0, sizeof(done));
   for(int i=0; i<n; i++) {
      int x = a[i] - 'a';
      int y = b[i] - 'a';
      if(x > y) {
         puts("-1");
         return;
      }
      else if(x ^ y) done[x][y] = 1;
   }

   int ans = 0;
   for(int i=1; i<20; i++) {
      set <int> st;
      for(int j=0; j<i; j++) {
         if(done[j][i]) {
            memset(vis, 0, sizeof vis);
            dfs(j);
            for(int k=19; k>=0; k--) {
               if(vis[k]) {
                  st.insert(k);
                  break;
               }
            }
         }
      }
      ans += st.size();
      for(int x : st) g[x].push_back(i);
   }

   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}