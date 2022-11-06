#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   ll sum = 0;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), sum += a[i];

   sum <<= 1;
   ll dv = n;
   ll g = __gcd(sum, dv);
   sum /= g, dv /= g;

   if(dv > 1) {
      puts("0");
      return;
   }

   ll ans = 0;
   map <int,int> mp;
   for(int i=0; i<n; i++) {
      ans += mp[sum - a[i]];
      mp[a[i]]++;
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}