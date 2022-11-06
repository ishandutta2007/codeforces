#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2005;

int a[sz][sz];
pair <int,int> w[sz*sz];
bool s[sz][sz];

int main() {
   int n, k;
   cin >> n >> k;
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         scanf("%d", &a[i][j]);
         w[a[i][j]] = {i, j};
      }
   }

   int ul = INT_MAX, dl = INT_MAX;
   int ur = INT_MIN, dr = INT_MIN;

   k++;

   for(int c=n*n; c; c--) {
      auto [x, y] = w[c];

      if(x - y - k >= ul) continue;
      if(x + y - k >= dl) continue;
      if(x - y + k <= ur) continue;
      if(x + y + k <= dr) continue;

      s[x][y] = 1;

      ul = min(ul, x - y);
      dl = min(dl, x + y);
      ur = max(ur, x - y);
      dr = max(dr, x + y);
   }

   for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
         printf("%c", s[i][j] ? 'M' : 'G');
      }
      puts("");
   }
}