#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   ll a, b;
   scanf("%lld %lld", &a, &b);
   if(!a) puts("1");
   else printf("%lld\n", a + b * 2 + 1);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}