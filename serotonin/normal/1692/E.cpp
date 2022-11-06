#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int a[sz], when[sz], cum[sz];

void solve() {
   int n, s;
   scanf("%d %d", &n, &s);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), cum[i] = a[i] + cum[i-1];

   if(cum[n] < s) {
      puts("-1");
      return;
   }

   for(int i=1; i<=n; i++) when[i] = n + 1;

   int ans = 0;
   for(int i=1; i<=n; i++) {
      when[cum[i]] = min(when[cum[i]], i);
      if(cum[i] < s) continue;
      int bad = cum[i] - s;
      ans = max(ans, i - when[bad]);
   }
   printf("%d\n", n - ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}