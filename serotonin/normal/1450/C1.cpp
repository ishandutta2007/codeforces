#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 305;

typedef pair <int,int> pii;
#define x first
#define y second

int n;
char s[sz][sz];
bool vis[sz][sz];
vector <pii> now;

void dfs(int i, int j) {
   if(i<0 || j<0 || i>=n || j>=n) return;
   if(vis[i][j] || s[i][j] != 'X') return;
   vis[i][j] = 1;
   now.emplace_back(i, j);
   dfs(i+1, j);
   dfs(i-1, j);
   dfs(i, j+1);
   dfs(i, j-1);
}

void solve() {
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%s", s[i]);
   memset(vis, 0, sizeof(vis));

   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         if(vis[i][j] || s[i][j] != 'X') continue;
         now.clear();
         dfs(i, j);

         int c[3] = {};
         for(auto &p : now) {
            int k = p.x + p.y;
            c[k % 3]++;
         }

         int w = 0;
         for(int i=1; i<3; i++) if(c[i] < c[w]) w = i;

         for(auto &p : now) {
            int k = p.x + p.y;
            if(k % 3 == w) s[p.x][p.y] = 'O';
         }
      }
   }

   for(int i=0; i<n; i++) printf("%s\n", s[i]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}