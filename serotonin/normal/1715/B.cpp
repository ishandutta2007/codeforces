#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

ll a[sz];

void solve() {
   ll n, k, b, s;
   scanf("%lld %lld %lld %lld", &n, &k, &b, &s);

   b *= k;
   ll ex = (k - 1) * n;
   if(b <= s and ex >= s - b) {
      ll sum = s;
      ll ex = s - b;
      for(int i=0; i<n; i++) a[i] = 0;
      for(int i=0; i<n; i++) {
         if(ex > k - 1) a[i] += k - 1;
         else a[i] += ex;
         ex -= a[i];
         s -= a[i];
      }
      a[0] += s;
      b /= k;
      for(int i=0; i<n; i++) {
         printf("%lld ", a[i]);
         sum -= a[i];
         b -= a[i] / k;
      }
      assert(!sum and !b);
      puts("");
   }
   else puts("-1");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}