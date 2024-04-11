#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+5;

void solve() {
   ll n;
   scanf("%lld", &n);
   ll x = n % 2020;
   if(!x) puts("YES");
   else {
      ll y = n / 2020;
      if(y >= x) puts("yes");
      else puts("no");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}