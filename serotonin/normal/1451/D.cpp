#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

ll r;
vector <ll> v;

ll fnc(ll i) {
   ll x = r - i * i;
   return upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
}

void solve() {
   ll d, k;
   scanf("%lld %lld", &d, &k);
   r = (d * d) / (k * k);
   ll b = -1;
   bool yes = 1;
   for(ll i=0; i*i<=r; i++) {
      ll j = fnc(i);
      if(i > j) break;
      if(fnc(i) == fnc(i+1)) continue;
      ll a = i + j;
      if(a & 1) b = i, yes = 0;
      else yes = 1;
   }

   if(b < 0 || (yes && b + 1 < fnc(b))) puts("Utkarsh");
   else puts("Ashish");
}

int main() {
   for(ll i=0; i<sz; i++) v.push_back(i * i);
   int t;
   cin >> t;
   while(t--) solve();
}