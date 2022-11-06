#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int a[sz], cum[sz];
bool ya[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=1; i<n; i++) ya[i] = a[i] < (a[i+1] << 1);
   for(int i=1; i<n; i++) cum[i] = ya[i] + cum[i-1];

   int ans = 0;
   for(int i=k; i<n; i++) {
      ans += cum[i] - cum[i-k] == k;
   }
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}