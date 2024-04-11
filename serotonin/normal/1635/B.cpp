#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];

void solve() {
   int n, ans = 0;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=2; i<n; i++) {
      if(a[i] > a[i-1] and a[i] > a[i+1]) {
         ans++;
         if(i == n - 1) a[i+1] = a[i];
         else a[i+1] = max(a[i+2], a[i]);
      }
   }
   printf("%d\n", ans);
   for(int i=1; i<=n; i++) printf("%d ", a[i]); puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}