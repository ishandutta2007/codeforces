#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   if(k == 1) {
      n -= 2;
      printf("%d\n", n + 1 >> 1);
      return;
   }

   int ans = 0;
   for(int i=1; i<n-1; i++) ans += a[i] > a[i-1] + a[i+1];
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}