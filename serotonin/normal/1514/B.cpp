#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7, mod = 1e9+7;

bool a[sz];

void solve() {
   ll n, k;
   scanf("%lld %lld", &n, &k);
   ll ans = 1;
   while(k--) ans = ans * n % mod;
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}