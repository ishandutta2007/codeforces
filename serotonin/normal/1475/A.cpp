#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

void solve() {
   ll n;
   scanf("%lld", &n);
   while(n % 2 == 0) n >>= 1;
   if(n > 1) puts("YES");
   else puts("NO");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}