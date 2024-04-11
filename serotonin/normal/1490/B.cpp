#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   int c[3] = {};
   for(int i=0; i<n; i++) scanf("%d", &a[i]), c[a[i] % 3]++;
   int x = n / 3;
   int ans = 0;
   for(int i=0; i<3; i++) {
      int z = max(0, c[i] - x);
      ans += z;
      c[i] -= z, c[(i+1) % 3] += z;
   }
   for(int i=0; i<3; i++) {
      int z = max(0, c[i] - x);
      ans += z;
      c[i] -= z, c[(i+1) % 3] += z;
   }
   for(int i=0; i<3; i++) {
      int z = max(0, c[i] - x);
      ans += z;
      c[i] -= z, c[(i+1) % 3] += z;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}