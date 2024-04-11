#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

int a[sz][sz];
bool vis[sz][sz];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void solve() {
   int n, ans = 0;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) 
      for(int j=1; j<=n; j++) 
         scanf("%d", &a[i][j]), vis[i][j] = 0;
         
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         bool yes = 1;
         for(int k=0; k<4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x and y and x <= n and y <= n) {
               if(vis[x][y]) yes = 0;
            }
         }
         if(!yes) continue;
         for(int k=0; k<4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x and y and x <= n and y <= n) {
               vis[x][y] = 1;
            }
         }
         ans ^= a[i][j];
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}