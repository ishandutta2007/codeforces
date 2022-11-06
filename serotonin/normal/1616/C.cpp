#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   int ans = n - 1;
   for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
         int v = a[j] - a[i], d = j - i;
         int g = __gcd(abs(v), d);
         v /= g, d /= g;
         int now = 0;
         for(int k=i, b=a[i]; k<n; k+=d, b+=v) {
            now += a[k] == b;
         }
         ans = min(ans, n - now);
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}