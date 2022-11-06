#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 55;

int n, m;
char s[sz][sz];
bool vis[sz][sz];

bool inside(int x, int y)
{
   if(x < 0 || y < 0 || x >= n || y >= m) return 0;
   return 1;
}

bool fnc(int x, int y)
{
   if(!inside(x, y)) return 0;
   if(s[x][y] == 'G') return 1;
   if(s[x][y] == '.') s[x][y] = '#';
   return 0;
}

void dfs(int x, int y)
{
   if(!inside(x, y)) return;
   if(s[x][y] == '#' || s[x][y] == 'B') return;
   if(vis[x][y]) return;
   vis[x][y] = 1;
   dfs(x-1, y);
   dfs(x+1, y);
   dfs(x, y-1);
   dfs(x, y+1);
}

int main()
{
   int t;
   cin >> t;
   while(t--) {
      scanf("%d %d", &n, &m);
      for(int i=0; i<n; i++) scanf("%s", s[i]);

      bool fuck = 0;
      for(int i=0; i<n; i++) {
         for(int j=0; j<m; j++) {
            if(s[i][j] == 'B') {
               fuck |= fnc(i-1, j);
               fuck |= fnc(i+1, j);
               fuck |= fnc(i, j+1);
               fuck |= fnc(i, j-1);
            }
         }
      }

      memset(vis, 0, sizeof (vis));
      dfs(n-1, m-1);

      for(int i=0; i<n; i++) {
         for(int j=0; j<m; j++) {
            if(s[i][j] == 'G' && !vis[i][j]) {
               fuck = 1;
            }
         }
      }

      if(fuck) puts("No");
      else puts("Yes");
   }
}