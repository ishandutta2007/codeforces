#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   ll n;
   scanf("%lld", &n);
   if(n & 1) n++;
   n >>= 1;
   n = max(n, 3LL);
   printf("%lld\n", 5 * n);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}