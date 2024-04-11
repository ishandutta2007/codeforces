#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   
   map <int,int> mp;
   for(int i=0; i<n; i++) mp[a[i]]++;

   ll ans = n / 2, lhs = 0, rhs = n;
   for(auto [x, c] : mp) {
      lhs += c;
      rhs -= c;
      ans = max(ans, lhs * rhs);
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}