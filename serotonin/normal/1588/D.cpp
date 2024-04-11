#include <bits/stdc++.h>
using namespace std;

string s[10];
int n, dp[53][1<<10], to[53][1<<10], whe[10][53][2];

int fnc(int pc, int m) {
   int &w = dp[pc][m];
   if(w >= 0) return w; w = 0;
   int upto[n];
   for(int i=0; i<n; i++) {
      int f = (m & (1 << i)) > 0;
      upto[i] = whe[i][pc][f];
   }
   for(int k=0; k<52; k++) {
      int msk = 0;
      bool ya = 1;
      for(int i=0; i<n; i++) {
         int j = whe[i][k][0];
         if(j > upto[i]) continue;
         j = whe[i][k][1];
         if(j > upto[i]) {
            msk |= 1 << i;
            continue;
         }
         ya = 0;
         break;
      }
      if(!ya) continue;
      int now = 1 + fnc(k, msk);
      if(now > w) {
         w = now;
         to[pc][m] = k;
      }
   }
   return w;
}

void go(int pc, int m) {
   int k = to[pc][m];
   if(k < 0) return;
   printf("%c", k < 26 ? 'a' + k : 'A' + k - 26);
   
   int upto[n];
   for(int i=0; i<n; i++) {
      int f = (m & (1 << i)) > 0;
      upto[i] = whe[i][pc][f];
   }
   
   m = 0;
   for(int i=0; i<n; i++) {
      if(whe[i][k][0] <= upto[i]) m |= 1 << i;
   }
   go(k, m);
}

void solve() {
   cin >> n;
   for(int i=0; i<n; i++) cin >> s[i];
   for(int i=0; i<n; i++) s[i] = (char)('Z' + 1) + s[i];
   memset(whe, -1, sizeof whe);
   memset(dp, -1, sizeof dp);
   memset(to, -1, sizeof to);
   for(int i=0; i<n; i++) {
      bool d[53] = {};
      for(int j=0; j<s[i].size(); j++) {
         char ch = s[i][j];
         int x = ch >= 'a' ? ch - 'a' : ch - 'A' + 26;
         whe[i][x][d[x]] = j;
         d[x] = 1;
      }
   }
   printf("%d\n", fnc(52, 0));
   go(52, 0); puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}