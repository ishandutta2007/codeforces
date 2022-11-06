#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+5;

int a[sz], cum[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), cum[i] = a[i] ^ cum[i-1];

   for(int i=1; i<n; i++) {
      if(cum[i] == (cum[n] ^ cum[i])) {
         puts("YES");
         return;
      }
      for(int j=i+1; j<n; j++) {
         if((cum[j] ^ cum[i]) == cum[i] and (cum[n] ^ cum[j]) == cum[i]) {
            puts("YES");
            return;
         }
      }
   }
   if(!cum[n]) {
      for(int i=1; i<n; i++) if(!cum[i]) {
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