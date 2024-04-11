#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

char s[sz];
int dp[sz][sz][2][2];
bool vis[sz][sz][2][2];

// x = 00, y = 01, z = 0

int fnc(int x, int y, int z, int f) {
   if(!x and !y and !z) return 0;

   int &w = dp[x][y][z][f];
   bool &v = vis[x][y][z][f];
   if(v) return w; v = 1;

   w = sz;
   if(y and !f) w = min(w, -fnc(x, y, z, 1));
   if(x) w = min(w, 1 - fnc(x - 1, y + 1, z, 0));
   if(y) w = min(w, 1 - fnc(x, y - 1, z, 0));
   if(z) w = min(w, 1 - fnc(x, y, z - 1, 0));
   return w;
}

void solve() {
   int n;
   scanf("%d %s", &n, s);
   int x = 0, y = 0, z = 0;
   for(int i=0; i<n; i++) {
      if(s[i] == '0' and s[n - 1 - i] == '0') x++;
      else if(s[i] == '0') y++;
   }
   if(x & 1) z = 1, x--;
   x >>= 1;

   int ans = fnc(x, y, z, 0);
   if(ans < 0) puts("ALICE");
   else if(!ans) puts("DRAW");
   else puts("BOB");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}