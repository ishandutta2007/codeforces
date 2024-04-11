#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505;

int n, m, dp[sz][sz][sz], go[sz][2];
char a[sz], b[sz];
vector <int> pos;

int fnc(int i, int j, int rem) {
   if(rem < 0) return sz;
   if(i == n) {
      if(!rem) return 0;
      return sz;
   }

   int &w = dp[i][j][rem];
   if(w >= 0) return w; w = sz;

   w = min(w, (a[i] != '0') + fnc(i + 1, go[j][0], rem - (j == m - 1 and b[j] == '0')));
   w = min(w, (a[i] != '1') + fnc(i + 1, go[j][1], rem - (j == m - 1 and b[j] == '1')));

   return w;
}

int main() {
   cin >> n >> m;
   scanf("%s %s", a, b);

   string r, bb = b;
   for(int i=0; i<m; i++) {
      for(int j=0; j<2; j++) {
         char ch = '0' + j;
         string s = r + ch;
         for(int k=0; k<s.size(); k++) {
            int d = s.size() - k;
            if(d < m and bb.substr(0, d) == s.substr(k, d)) {
               go[i][j] = d;
               break;
            }
         }
      }
      r += b[i];
   }

   memset(dp, -1, sizeof(dp));
   for(int i=0; i<n-m+2; i++) {
      int ans = fnc(0, 0, i);
      if(ans == sz) printf("-1 ");
      else printf("%d ", ans);
   }
}