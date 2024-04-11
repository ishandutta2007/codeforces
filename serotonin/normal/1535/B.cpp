#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n, [](int x, int y) {
      return (x & 1) < (y & 1);
   });
   int ans = 0;
   for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
         if(__gcd(a[i], a[j] << 1) > 1) ans++;
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}