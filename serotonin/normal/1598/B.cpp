#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e4+5;

int a[sz][5];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) {
      for(int j=0; j<5; j++) scanf("%d", &a[i][j]);
   }

   for(int i=0; i<5; i++) {
      for(int j=i+1; j<5; j++) {
         int x = 0, y = 0, b = 0, none = 0;
         for(int k=0; k<n; k++) {
            x += a[k][i], y += a[k][j];
            b += a[k][i] & a[k][j];
            if(!a[k][i] and !a[k][j]) none = 1;
         }
         if(none) continue;
         x -= b, y -= b;
         if(min(x, y) + b >= n / 2) {
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