#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int n, a[sz], dp[sz], prvnotfive[sz];
char s[3][sz];
bool vis[3];

bool go(int x, int y) {
   if(x < 0 or x > 2) return 0;
   if(vis[x]) return 0;
   if(s[x][y] == '0') return 0;
   if(s[x][y-1] == '1') return 1;
   vis[x] = 1;
   return go(x - 1, y) | go(x + 1, y);
}

bool fnc(int x, int y) {
   if(s[x][y] == '0') return 0;
   if(x and s[x-1][y] == '1') return 0;
   memset(vis, 0, sizeof vis);
   return !go(x, y);
}

int main() {
   cin >> n;
   for(int i=0; i<3; i++) scanf("%s", s[i] + 1);

   for(int j=1; j<=n; j++) {
      a[j] = 0;
      for(int i=0; i<3; i++) if(s[i][j] == '1')
         a[j] |= 1 << i;
   }

   for(int j=2; j<=n; j++) {
      for(int i=0; i<3; i++) {
         dp[j] += fnc(i, j);
      }
   }

   for(int j=2; j<=n; j++) {
      prvnotfive[j] = prvnotfive[j-1];
      if(a[j-1] != 5) prvnotfive[j] = j-1;
   }

   vector <pair<int,int>> vec;
   for(int j=1; j<=n; j++) {
      if(a[j] == 7 and a[j-1] == 5) {
         dp[j]--;
         int k = prvnotfive[j];
         if(a[k] == 7) {
            vec.emplace_back(k, j);
            // printf("%d %d\n", k, j);
         }
      }
      // printf("%d ", dp[j]);
      dp[j] += dp[j-1];
   }
   // puts("");

   int q;
   cin >> q;
   while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      int ans = dp[r] - dp[l];
      if(a[l] == 5) ans += 2;
      else if(a[l]) ans++;
      
      int x = lower_bound(vec.begin(), vec.end(), make_pair(l, -1)) - vec.begin();
      if(x < vec.size()) {
         int y = upper_bound(vec.begin(), vec.end(), make_pair(r, -1)) - vec.begin() - 1;
         while(y >= 0 and vec[y].second > r) y--;
         ans += max(0, y - x + 1);
      }

      printf("%d\n", ans);
   }
}