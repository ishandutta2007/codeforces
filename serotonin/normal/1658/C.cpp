#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   int one = 0;
   for(int i=1; i<=n; i++) {
      one += a[i] == 1;
   }

   if(one == 1) {
      a[0] = a[n];
      for(int i=1; i<=n; i++) {
         if(a[i] > a[i-1] + 1) {
            puts("NO");
            return;
         }
      }
      puts("YES");
   }
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}