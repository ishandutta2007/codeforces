#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 505;

ll a[sz];

int main()
{
   int n;
   cin >> n;
   for(int i=0; i<n; i++) cin >> a[i];

   if(n < 4) {
      ll ans = 0;
      for(int i=0; i<n; i++) ans |= a[i];
      cout << ans;
      exit(0);
   }

   ll ans = 0;
   for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
         for(int k=j+1; k<n; k++) {
            ll now = a[i] | a[j] | a[k];
            ans = max(ans, now);
         }
      }
   }

   printf("%lld\n", ans);
}