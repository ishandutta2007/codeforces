#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   ll n;
   scanf("%lld", &n);
   ll b = n - 1;
   ll aa = 2 * b + 1;
   ll a = sqrt(aa) + 20;
   while(a * a > aa) a--;
   ll ans = (a + 1) / 2;
   printf("%lld\n", ans - 1);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}