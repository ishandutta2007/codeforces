#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

char a[sz][sz], b[sz][sz];
int d[sz][sz], now[sz][sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%s", a[i]);
   for(int i=0; i<n; i++) scanf("%s", b[i]);
   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         if(a[i][j] ^ b[i][j]) d[i][j] = 1;
         else d[i][j] = 0;
      }
   }
   memset(now, 0, sizeof(now));
   for(int i=0; i<n; i++) if(d[0][i]) {
      for(int j=0; j<n; j++) now[j][i] = 1;
   }
   bool ans = 1;
   for(int i=1; i<n; i++) {
      bool yes = 1;
      for(int j=0; j<n; j++) if(d[i][j] ^ now[i][j]) yes = 0;
      if(yes) continue;
      yes = 1;
      for(int j=0; j<n; j++) {
         now[i][j] ^= 1;
         if(d[i][j] ^ now[i][j]) yes = 0;
      }
      if(!yes) ans = 0;
   }
   if(ans) {
      puts("yes");
      return;
   }

   memset(now, 0, sizeof(now));
   for(int i=0; i<n; i++) if(!d[0][i]) {
      for(int j=0; j<n; j++) now[j][i] = 1;
   }
   ans = 1;
   for(int i=1; i<n; i++) {
      bool yes = 1;
      for(int j=0; j<n; j++) if(d[i][j] ^ now[i][j]) yes = 0;
      if(yes) continue;
      yes = 1;
      for(int j=0; j<n; j++) {
         now[i][j] ^= 1;
         if(d[i][j] ^ now[i][j]) yes = 0;
      }
      if(!yes) ans = 0;
   }
   if(ans) {
      puts("yes");
      return;
   }

   puts("no");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}