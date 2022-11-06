#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   map <int,int> mp;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), a[i] -= i, mp[a[i]]++;

   ll ans = 0;
   for(auto [x, y] : mp) ans += y * (y - 1LL) / 2;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}