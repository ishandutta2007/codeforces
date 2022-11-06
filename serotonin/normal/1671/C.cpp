#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];
ll cum[sz];

void solve() {
   int n; ll m;
   scanf("%d %lld", &n, &m);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   sort(a, a+n+1);

   for(int i=1; i<=n; i++) cum[i] = a[i] + cum[i-1];

   ll d = 0, ans = 0;
   for(int i=n; i; i--) {
      ll rem = m - cum[i] - d * i;
      if(rem < 0) continue;
      ll t = 1 + rem / i;
      ans += t * i;
      d += t;
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}