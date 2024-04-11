#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   a[n] = a[0];

   int ans = INT_MIN;
   for(int i=1; i<=n; i++) ans = max(a[i-1] - a[i], ans);

   for(int i=1; i<n; i++) ans = max(ans, a[i] - a[0]);

   for(int i=0; i<n-1; i++) ans = max(a[n-1] - a[i], ans);

   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}