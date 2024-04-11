#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], w[sz];

void solve()
{
   int n, k;
   cin >> n >> k;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);
   for(int i=0; i<k; i++) scanf("%d", &w[i]);
   sort(w, w+k, greater<int>());

   ll ans = 0;
   for(int i=0; i<k; i++) ans += a[n-1-i];
   for(int i=0, j=0, r=n; i<k; i++) {
      if(w[i] == 1) {
         ans += a[--r];
         continue;
      }
      ans += a[j];
      j += w[i] - 1;
   }
   printf("%lld\n", ans);
}

int main()
{
   int t;
   cin >> t;
   while(t--) solve();
}