#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

ll a[sz];

void solve() {
   ll n, k;
   cin >> n >> k;
   ll mx = LLONG_MIN;
   for(int i=0; i<n; i++) scanf("%lld", &a[i]), mx = max(mx, a[i]);
   k--;
   for(int i=0; i<n; i++) a[i] = mx - a[i];
   if(k & 1) {
      mx = 0;
      for(int i=0; i<n; i++) mx = max(mx, a[i]);
      for(int i=0; i<n; i++) a[i] = mx - a[i];
   }
   for(int i=0; i<n; i++) printf("%lld ", a[i]);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}