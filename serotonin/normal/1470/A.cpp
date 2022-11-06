#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], c[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   sort(a+1, a+n+1);
   for(int i=1; i<=m; i++) scanf("%d", &c[i]);

   ll ans = 0;
   for(int i=1; i<=n; i++) ans += c[a[i]];
   for(int i=n, j=1; i && j<=m; i--, j++) {
      if(j >= a[i]) break;
      ans += c[j] - c[a[i]];
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}