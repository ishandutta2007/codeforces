#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

int a[sz][sz], mxcol[sz], mncol[sz];
char s[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) {
      scanf("%s", s + 1);
      for(int j=1; j<=m; j++) a[i][j] = s[j] == 'B';
   }

   for(int j=1; j<=m; j++) {
      mxcol[j] = 0, mncol[j] = n + 1;
      for(int i=1; i<=n; i++) if(a[i][j]) {
         mxcol[j] = max(mxcol[j], i);
         mncol[j] = min(mncol[j], i);
      }
   }

   tuple <int,int,int> ans = {n + m, 0, 0};
   for(int i=1; i<=n; i++) {
      priority_queue <int> lhs, rhs;
      for(int j=1; j<=m; j++) {
         if(!mxcol[j]) continue;
         int y = max(mxcol[j] - i, i - mncol[j]);
         if(y < 0) continue;
         rhs.push(y + j);
         lhs.push(y - j);
      }
      for(int j=1; j<=m; j++) {
         int now = max(lhs.top() + j, rhs.top() - j);
         tuple <int,int,int> idk = {now, i, j};
         ans = min(ans, idk);
      }
   }
   auto [v, x, y] = ans;
   printf("%d %d\n", x, y);
}

int main() {
   int t; 
   cin >> t;
   while(t--) solve();
}