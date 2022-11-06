#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

char s[11][11];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%s", s[i]);

   int up = n, lf = m;
   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(s[i][j] == 'E') continue;
         up = min(up, i);
         lf = min(lf, j);
      }
   }

   for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
         if(s[i][j] == 'E') continue;
         if(i <= up and j <= lf) {
            puts("YES");
            return;
         }
      }
   }
   puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}