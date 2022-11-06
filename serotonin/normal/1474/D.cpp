#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

ll a[sz], lhs[sz], rhs[sz], lmn[sz], rmn[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);

   lmn[1] = lhs[1] = a[1];
   for(int i=2; i<=n; i++) {
      lhs[i] = a[i] - lhs[i-1];
      lmn[i] = min(lhs[i], lmn[i-1]);
   }
   rmn[n] = rhs[n] = a[n];
   for(int i=n-1; i; i--) {
      rhs[i] = a[i] - rhs[i+1];
      rmn[i] = min(rhs[i], rmn[i+1]);
   }

   if(a[1] == rhs[2] and rmn[2] >= 0) {
      puts("YES");
      return;
   }
   if(a[n] == lhs[n-1] and lmn[n-1] >= 0) {
      puts("YES");
      return;
   }

   for(int i=2; i<=n-1; i++) {
      if(a[i] == lhs[i-1] + rhs[i+1] and lmn[i-1] >= 0 and rmn[i+1] >= 0) {
         puts("YES");
         return;
      }
   }

   for(int i=2; i<=n-2; i++) {
      if(lmn[i-1] >= 0 and rmn[i+2] >= 0) {
         ll x = a[i+1] - lhs[i-1];
         if(x < 0) continue;
         x = a[i] - x;
         if(x < 0) continue;
         if(rhs[i+2] == x) {
            puts("YES");
            return;
         }
      }
   }

   if(n <= 2) {
      puts("NO");
      return;
   }

   if(rmn[3] >= 0) {
      if(a[1] - rhs[3] == a[2]) {
         puts("YES");
         return;
      }
   }

   if(lmn[n-2] >= 0) {
      if(a[n] - lhs[n-2] == a[n-1]) {
         puts("YES");
         return;
      }
   }

   puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}