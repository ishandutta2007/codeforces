#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll sz = 5005;

ll n, a[sz], dp[sz][sz];

ll fnc(ll pos, ll cut) {
   ll &w = dp[pos][cut];
   if(w < 0) {
      w = 1 + fnc(pos+1, 0);

      cut = min(cut, a[pos]);
      ll na = a[pos] - cut;
      w = min(w, na + fnc(pos+1, min(n, cut+na)));

      w = min(w, 1 + fnc(pos+1, cut));
   }
   return w;
}

int main() {
   cin >> n;
   for(ll i=0; i<n; i++) scanf("%lld", &a[i]);
   memset(dp, -1, sizeof(dp));
   cout << fnc(0, 0);
}