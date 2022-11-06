#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

void solve() {
   int n, a[5] = {};
   scanf("%d", &n);
   for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      a[x]++;
   }
   bool yes = 0;
   for(int i=0; i<=a[1]; i++) {
      for(int j=0; j<=a[2]; j++) {
         int x = i + j * 2;
         int y = (a[1] - i) + (a[2] - j) * 2;
         if(x == y) yes = 1;
      }
   }
   if(yes) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}