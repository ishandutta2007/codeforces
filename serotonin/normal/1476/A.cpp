#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

void solve() {
   ll n, k;
   scanf("%lld %lld", &n, &k);
   if(n == 1) printf("%lld\n", k);
   else if(n % k == 0) puts("1");
   else if(n > k) puts("2");
   else printf("%lld\n", (k + n - 1) / n);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}