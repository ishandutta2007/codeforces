#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int n, a[sz];

ll calc(ll one, ll two) {
   if(two < one) return 2 * one - 1;
   return 2 * two;
}

ll fnc(int z) {
   ll one = 0, two = 0;
   for(int i=0; i<n; i++) {
      int ex = z - a[i];
      if(ex & 1) one++, ex--;
      two += ex >> 1;
   }
   if(two < one) return 2 * one - 1;
   if(two == one) return 2 * one;

   ll d = two - one; d /= 3;
   d = max(0LL, d - 3);
   two -= d, one += d * 2;

   ll ans = LLONG_MAX;
   for(int i=0; i<10; i++) {
      ans = min(ans, calc(one, two));
      one += 2, two--;
   }
   return ans;
}

void solve() {
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a + n);
   printf("%lld\n", min(fnc(a[n-1]), fnc(a[n-1] + 1)));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}