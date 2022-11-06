#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e6+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   int g = 0;
   for(int i=1; i<=n; i++) g = __gcd(g, a[i]);

   if(g == 1) {
      puts("0");
      return;
   }
   
   int ans = 3;
   for(int i=n; i; i--) if(__gcd(g, i) == 1) {
      ans = min(ans, n - i + 1);
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}