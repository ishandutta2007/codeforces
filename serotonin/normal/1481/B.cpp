#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

int go(int n) {
   for(int i=1; i<n; i++) {
      if(a[i] < a[i+1]) {
         a[i]++;
         return i;
      }
   }
   return -1;
}

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   int ans = -1;
   for(int i=0; i<k; i++) {
      ans = go(n);
      if(ans < 0) break;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}