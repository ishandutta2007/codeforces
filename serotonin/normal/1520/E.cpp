#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

char s[sz];

ll fnc(ll x) {
   return x * (x + 1) / 2;
}

void solve() {
   int n;
   scanf("%d %s", &n, s);
   int c = 0; ll sum = 0;
   for(int i=0; i<n; i++) if(s[i] == '*') c++, sum += i;

   if(!c) {
      puts("0");
      return;
   }

   ll ans = LLONG_MAX, cut = 0, rhs = c;
   for(int i=0, j=0; i<n; i++) {
      if(s[i] == '*') {
         j++, rhs--, cut += i;
         ll now = (sum - cut) - (fnc(i + rhs) - fnc(i));
         now += (fnc(i) - fnc(i - j)) - cut;
         ans = min(ans, now);
      }
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}