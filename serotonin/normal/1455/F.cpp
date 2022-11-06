#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505;

int n, k;
char cz;
bool vis[sz][27][27];
string s, dp[sz][27][27];

char cnv(char x) {
   if(x == 'a' || x == cz) return 'a';
   return x - 1;
}

string fnc(int i, char pch, char cch) {
   if(i >= n) return string(1, pch);
   int p = pch - 'a' + 1, c = cch - 'a' + 1;
   if(vis[i][p][c]) return dp[i][p][c];
   vis[i][p][c] = 1;

   string &now = dp[i][p][c];
   now.assign(n-i+1, cz);
   char nch = s[i+1];

   if(i < n-1) {
      if(pch < cch && pch < nch) {
         if(cnv(cch) < cnv(nch)) now = pch + fnc(i+1, cnv(cch), nch);   // 1
         else if(cnv(cch) < cnv(nch)) now = pch + (cnv(nch) + fnc(i+2, cch, s[i+2]));   // 3
         else {
            now = pch + fnc(i+1, cnv(cch), nch);   // 1
            now = min(now, pch + (cnv(nch) + fnc(i+2, cch, s[i+2])));   // 3
         }
      }
      else if(cch < pch && cch < nch) now = cch + fnc(i+1, pch, nch);   // 2
      else if(nch < cch && nch < pch) now = nch + (pch + fnc(i+2, cch, s[i+2]));  // 4
      else if(pch == cch && cch == nch) now = pch + fnc(i+1, cnv(cch), nch);   // 1
      else {
         if(pch <= cch) now = pch + fnc(i+1, cnv(cch), nch);   // 1
         else now = cch + fnc(i+1, pch, nch);   // 2
         if(pch <= nch) now = min(now, pch + (cnv(nch) + fnc(i+2, cch, s[i+2])));   // 3
         else now = min(now, nch + (pch + fnc(i+2, cch, s[i+2])));  // 4
      }
   }
   else {
      if(pch <= cch) now = pch + fnc(i+1, cnv(cch), nch);
      else now = cch + fnc(i+1, pch, nch);
   }

   return now;
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0);
   int t;
   cin >> t;
   while(t--) {
      cin >> n >> k >> s;
      s += 'z'; cz = 'a' + k - 1;
      memset(vis, 0, sizeof(vis));
      cout << fnc(0, 'a', s[0]).substr(1, n) << '\n';
   }
}