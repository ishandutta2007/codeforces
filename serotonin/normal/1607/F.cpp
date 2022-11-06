#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005;

char s[sz][sz];
int n, m, cyc[sz][sz], vis[sz][sz], dp[sz][sz], ci, cj;

int go(int i, int j, int k) {
   if(vis[i][j] > 0) {
      ci = i, cj = j;
      return k - vis[i][j];
   }
   if(vis[i][j] < 0) return 0;
   vis[i][j] = k;

   int &w = cyc[i][j], x = i, y = j;
   char ch = s[i][j];
   if(ch == 'L') j--;
   else if(ch == 'R') j++;
   else if(ch == 'D') i++;
   else i--;

   if(i < 0 or i >= n or j < 0 or j >= m) {
      vis[x][y] = -1;
      return 0;
   }
   int v = go(i, j, k + 1);
   if(ci >= 0) w = v;
   if(ci == x and cj == y) ci = cj = -1;
   vis[x][y] = -1;
   return v;
}

int dfs(int i, int j) {
   if(i < 0 or i >= n or j < 0 or j >= m) return 0;
   int &w = dp[i][j];
   if(w) return w;
   if(cyc[i][j]) return w = cyc[i][j];

   char ch = s[i][j];
   if(ch == 'L') j--;
   else if(ch == 'R') j++;
   else if(ch == 'D') i++;
   else i--;
   return w = 1 + dfs(i, j);
}

void solve() {
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%s", s[i]);

   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         cyc[i][j] = vis[i][j] = dp[i][j] = 0;
      }
   }

   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(vis[i][j]) continue;
         ci = cj = -1, go(i, j, 1);
      }
   }

   tuple <int,int,int> ans = {0, 1, 1};
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(cyc[i][j]) ans = max(ans, {cyc[i][j], i, j});
         else ans = max(ans, {dfs(i, j), i, j});
//         printf("%d %d = %d\n", i, j, cyc[i][j]);
      }
   }
   printf("%d %d %d\n", get<1>(ans) + 1, get<2>(ans) + 1, get<0>(ans));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}