#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005, inf = 1e9;

ll w;
int n, m, f, a[sz][sz], dp[2][sz][sz];
queue <pair<int,int>> q;

void fnc(int x, int y, int d) {
   if(a[x][y] < 0) return;
   if(d >= dp[f][x][y]) return;
   dp[f][x][y] = d;
   q.emplace(x, y);
}

void go(int sx, int sy) {
   q.emplace(sx, sy);
   for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++) dp[f][i][j] = inf;
   dp[f][sx][sy] = 0;
   while(!q.empty()) {
      auto [x, y] = q.front(); q.pop();
      int d = dp[f][x][y] + 1;
      fnc(x + 1, y, d);
      fnc(x - 1, y, d);
      fnc(x, y + 1, d);
      fnc(x, y - 1, d);
   }
}

int main() {
   scanf("%d %d %lld", &n, &m, &w);
   for(int i=1; i<=n; i++)
      for(int j=1; j<=m; j++)
         scanf("%d", &a[i][j]);
   f = 0, go(1, 1);
   f = 1, go(n, m);

   ll ans = LLONG_MAX;
   if(dp[0][n][m] < inf) ans = dp[0][n][m] * w;

   ll x = LLONG_MAX, y = LLONG_MAX;
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
         if(a[i][j] <= 0) continue;
         int dx = dp[0][i][j];
         if(dx < inf) x = min(x, w * dx + a[i][j]);
         int dy = dp[1][i][j];
         if(dy < inf) y = min(y, w * dy + a[i][j]);
      }
   }
   if(x < LLONG_MAX and y < LLONG_MAX) ans = min(ans, x + y);

   if(ans == LLONG_MAX) ans = -1;
   cout << ans;
}