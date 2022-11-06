#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1005;

int a[sz][sz];

int main() {
   int n, m, k;
   cin >> n >> m >> k;
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
         scanf("%d", &a[i][j]);
      }
   }
   while(k--) {
      int j;
      scanf("%d", &j);
      for(int i=1; i<=n; i++) {
         int &x = a[i][j];
         if(x != 2) {
            if(x == 3) j--;
            else j++;
            x = 2, i--;
         }
      }
      printf("%d ", j);
   }
}