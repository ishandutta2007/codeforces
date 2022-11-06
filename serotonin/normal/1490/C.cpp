#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e4+5;

ll a[sz];

void solve() {
   ll x;
   scanf("%lld", &x);
   for(ll i=1; ; i++) {
      ll z = i * i * i;
      if(z > x) break;
      ll b = x - z;
      int j = lower_bound(a+1, a+sz, b) - a;
      if(j < sz and a[j] == b) {
         puts("YES");
         return;
      }
   }
   puts("NO");
}

int main() {
   for(ll i=1; i<sz; i++) a[i] = i * i * i;
   int t;
   cin >> t;
   while(t--) solve();
}