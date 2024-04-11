#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int rout;
bool vis[55][725];
bool block[55][725];

void go(int r, int a) {
   if(vis[r][a] or block[r][a]) return;
   vis[r][a] = 1;
   if(r > rout) return;

   if(r > 1) go(r - 1, a);
   go(r + 1, a);
   go(r, a > 0 ? a - 1 : 720 - 1);
   go(r, a + 1 < 720 ? a + 1 : 0);
}

void solve() {
   int n;
   cin >> n;
   rout = 0;
   memset(block, 0, sizeof(block));
   while(n--) {
      char c;
      getchar();
      scanf("%c", &c);
      if(c == 'C') {
         int r, a1, a2;
         scanf("%d %d %d", &r, &a1, &a2);
         r <<= 1; a1 <<= 1, a2 <<= 1;
         rout = max(rout, r);
         while(1) {
            block[r][a1] = 1;
            if(a1 == a2) break;
            a1++; 
            if(a1 == 720) a1 = 0;
         }
      }
      else {
         int r1, r2, a;
         scanf("%d %d %d", &r1, &r2, &a);
         r1 <<= 1, r2 <<= 1; a <<= 1;
         for(int i=r1; i<=r2; i++) block[i][a] = 1;
      }
   }

   memset(vis, 0, sizeof(vis));
   go(1, 0);
   
   for(int i=0; i<720; i++) if(vis[rout + 1][i]) {
      puts("YES");
      return;
   }
   puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}