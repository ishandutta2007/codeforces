#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int n;
char s[3][sz], ans[sz];

int fnc(int x, int y) {
   int z = 0;
   for(int i=0; i<2*n; i++) z += s[y][i] == '0';
   char ch = '0';
   if(z < n) ch = '1';

   int r = 0, j=0;
   for(int i=0; i<2*n; i++) {
      if(s[x][i] == ch) {
         while(j < 2*n and s[y][j] != ch) ans[r++] = s[y][j++];
         if(s[y][j] == ch) j++;
      }
      ans[r++] = s[x][i];
   }
   while(j < 2*n) ans[r++] = s[y][j++];
   ans[r] = 0;
   return r;
}

void solve() {
   scanf("%d", &n);
   for(int i=0; i<3; i++) scanf("%s", s[i]);
   if(fnc(0, 1) <= 3 * n) puts(ans);
   else if(fnc(0, 2) <= 3 * n) puts(ans);
   else if(fnc(2, 1) <= 3 * n) puts(ans);
   else if(fnc(1, 0) <= 3 * n) puts(ans);
   else if(fnc(2, 0) <= 3 * n) puts(ans);
   else if(fnc(1, 2) <= 3 * n) puts(ans);
   else assert(0);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}