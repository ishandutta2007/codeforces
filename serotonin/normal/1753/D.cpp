#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 3e5+5, inf = 1e17;

int n, m, p, q;
string s[sz];
vector <ll> dp[sz];
vector <int> ara[sz];

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   cin >> n >> m >> p >> q;
   for(int i=0; i<n; i++) cin >> s[i];
   for(int i=0; i<n; i++) {
      dp[i].resize(m);
      for(int j=0; j<m; j++) dp[i][j] = inf;
      ara[i].resize(m);
      for(int j=0; j<m; j++) ara[i][j] = 0;
   }

   priority_queue <tuple<ll,int,int>> pq;
   for(int i=0, k=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(s[i][j] == '.') {
            dp[i][j] = 0;
            pq.emplace(0, i, j);
         }

         if(s[i][j] == 'U') 
            ara[i][j] = ara[i + 1][j] = ++k;
         
         if(s[i][j] == 'L') 
            ara[i][j] = ara[i][j + 1] = ++k;
      }
   }

   int dx[] = {-1, 1, 0, 0};
   int dy[] = {0, 0, -1, 1};
   while(!pq.empty()) {
      auto [d, x, y] = pq.top(); pq.pop();
      d = -d;

      for(int e=0; e<4; e++) {
         int sx = x + dx[e];
         int sy = y + dy[e];
         if(sx < 0 or sy < 0 or sx >= n or sy >= m or !ara[sx][sy]) continue;

         for(int f=0; f<4; f++) {
            int tx = sx + dx[f];
            int ty = sy + dy[f];
            if(tx < 0 or ty < 0 or tx >= n or ty >= m) continue;

            if(ara[sx][sy] != ara[tx][ty] or make_pair(sx, sy) == make_pair(tx, ty)) continue;

            bool sd = e < 2, td = f < 2;

            ll now = d + (sd == td ? q : p);
            if(now < dp[tx][ty]) {
               dp[tx][ty] = now;
               pq.emplace(-now, tx, ty);
            }
         }
      }
   }

   ll ans = inf;
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         int x = i, y = j;
         for(int e=0; e<4; e++) {
            int sx = x + dx[e];
            int sy = y + dy[e];
            if(sx < 0 or sy < 0 or sx >= n or sy >= m) continue;

            ans = min(ans, dp[x][y] + dp[sx][sy]);
         }
      }
   }

   if(ans == inf) puts("-1");
   else cout << ans;
}