#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+5;

void solve() {
   ll a, b;
   scanf("%lld %lld", &a, &b);
   if(b == 1) puts("NO");
   else {
      puts("YES");
      if(b == 2) printf("%lld %lld %lld\n", a, 3 * a, 4 * a);
      else printf("%lld %lld %lld\n", a, (b - 1) * a, b * a);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}