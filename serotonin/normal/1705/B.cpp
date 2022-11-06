#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   ll ans = 0;
   for(int i=0; i<n-1; i++) {
      if(!a[i] and ans) ans++;
      ans += a[i];
   }
   printf("%lld\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}