#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   int m = n / 2 + 1;
   for(int i=2; i<n; i++) a[i] = i+1;
   a[n] = min(2, m-1); a[m-1] = 1; a[1] = m;
   ll ans = 0;
   for(int i=m; i<=n; i++) ans += (i - 1LL) * (i - 1);
   for(int i=2; i<m; i++) ans += (ll)(n - i) * (n - i);
   printf("%lld\n", ans);
   for(int i=1; i<=n; i++) printf("%d ", a[i]);
   printf("\n%d\n", n-1);
   for(int i=2; i<m; i++) printf("%d %d\n", i, n);
   for(int i=m; i<=n; i++) printf("%d 1\n", i);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}