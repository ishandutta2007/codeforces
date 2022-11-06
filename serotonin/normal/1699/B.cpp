#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 55;

bool a[sz][sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) {
      int f = i % 4 == 2 or i % 4 == 3 ? 0 : 1;
      for(int j=1, k=f; j<=m; j+=2, k^=1) {
         a[i][j] = k;
         a[i][j + 1] = k ^ 1;
      }
   }
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
         int c = 0;
         if(i > 1) c += a[i-1][j] != a[i][j];
         if(i < n) c += a[i+1][j] != a[i][j];
         if(j < m) c += a[i][j+1] != a[i][j];
         if(j > 1) c += a[i][j-1] != a[i][j];
         assert(c == 2);
         printf("%d ", a[i][j]);
      }
      puts("");
   }
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}