#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz];

void solve() {
   int n;
   cin >> n;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   ll ans = 0;
   for(int i=1; i<n; i++) {
      if(a[i] < a[i-1]) {
         int ni;
         for(int j=i; j<n; j++) {
            if(a[j] > a[j-1]) break;
            ni = j;
         }
         ans += a[i-1] - a[ni];
         i = ni;
      }
      if(a[i] > a[i-1]) {
         for(int j=i; j<n; j++) {
            if(a[j] < a[j-1]) break;
            i = j;
         }
      }
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}