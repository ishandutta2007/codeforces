#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 405, inf = 1e9;

int n, m;
char s[sz][sz];

int dp[2][sz][sz], bcum[sz][sz], ecum[sz][sz], op[3][sz][sz], bst[sz][sz];

void solve() {
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%s", s[i]);

   for(int k=0; k<m; k++) {
      for(int i=0; i<n; i++) {
         bcum[k][i] = s[i][k] == '0';
         if(i) bcum[k][i] += bcum[k][i-1];
         ecum[k][i] = s[i][k] == '1';
         if(i) ecum[k][i] += ecum[k][i-1];
      }
   }

   for(int i=0; i<n; i++) for(int j=0; j<n; j++) bst[i][j] = -inf;

   int ans = inf;
   for(int k=0; k<m; k++) {
      for(int i=0; i<n; i++) {
         for(int j=i+4; j<n; j++) {
            int &w = dp[1][i][j] = 0;
            w += ecum[k][j-1] - ecum[k][i];
            w += s[i][k] == '0';
            w += s[j][k] == '0';
            if(k) w += dp[0][i][j];
            op[2][i][j] = w - (bcum[k][j-1] - bcum[k][i]);
            if(k >= 2) {
               bst[i][j] = max(bst[i][j], op[0][i][j]);
               if(k+1 < m) {
                  ans = min(ans, w - bst[i][j] + bcum[k+1][j-1] - bcum[k+1][i]);
               }
            }
//            printf("%d = %d\n", k, w);
         }
      }
      swap(dp[0], dp[1]);
      swap(op[0], op[1]);
      swap(op[1], op[2]);
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}