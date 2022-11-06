#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   bool ok = 1;
   for(int i=1; i<=n; i++) if(a[i] != i) ok = 0;
   if(ok) {
      puts("0");
      return;
   }

   if(a[1] == 1 and a[n] == n) {
      puts("1");
      return;
   }

   int ans = 0;
   if(a[1] != 1) ans++;
   if(a[n] != n) ans++;
   if(a[1] == n and a[n] == 1) ans++;
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}