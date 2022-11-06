#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   int ans = 0;
   for(int i=n-1; i; i--) {
      while(a[i] and a[i] >= a[i+1]) a[i] >>= 1, ans++;
      if(a[i] >= a[i+1]) {
         puts("-1");
         return;
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}