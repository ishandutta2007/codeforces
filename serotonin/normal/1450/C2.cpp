#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 305;

typedef pair <int,int> pii;
#define x first
#define y second

int n, c[2][3];
char s[sz][sz];
bool vis[sz][sz];
vector <pii> now;

void dfs(int i, int j) {
   if(i<0 || j<0 || i>=n || j>=n) return;
   if(vis[i][j] || s[i][j] == '.') return;
   vis[i][j] = 1;
   now.emplace_back(i, j);
   dfs(i+1, j);
   dfs(i-1, j);
   dfs(i, j+1);
   dfs(i, j-1);
}

int fnc(int f, int m) {
   return c[f][m] + c[f ^ 1][(m + 1) % 3];
}

void toggle(int i, int j) {
   char &c = s[i][j];
   if(c == 'X') c = 'O';
   else c = 'X';
}

void solve() {
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%s", s[i]);
   memset(vis, 0, sizeof(vis));

   int tot = 0, cnt = 0;
   for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
         if(s[i][j] != '.') tot++;
         if(vis[i][j] || s[i][j] == '.') continue;
         now.clear();
         dfs(i, j);

         memset(c, 0, sizeof(c));

         for(auto &p : now) {
            int k = p.x + p.y;
            int f = 0;
            if(s[p.x][p.y] == 'X') f = 1;
            c[f][k % 3]++;
         }

         int f = 0, k = 0;
         for(int i=0; i<2; i++) {
            for(int j=0; j<3; j++) {
               if(fnc(f, k) > fnc(i, j)) f = i, k = j;
            }
         }
         cnt += fnc(f, k);

         for(auto &p : now) {
            int nk = p.x + p.y;
            int nf = 0;
            if(s[p.x][p.y] == 'X') nf = 1;
            nk %= 3;

            if(nk == k && nf == f) toggle(p.x, p.y);
            else if(nk == (k + 1) % 3 && nf != f) toggle(p.x, p.y);
         }
      }
   }
   tot /= 3;
   assert(cnt <= tot);

   for(int i=0; i<n; i++) printf("%s\n", s[i]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}