#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz], zer[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   bool yes = 1;
   for(int i=2; i<=n; i++) if(a[i] < a[i-1]) yes = 0;
   if(yes) {
      puts("0");
      return;
   }

   for(int i=1; i<=n; i++) {
      zer[i] = zer[i-1];
      if(!a[i]) zer[i]++;
   }
   int ans = zer[n];
   for(int i=1; i<=n; i++) {
      int lhs = i - zer[i];
      int rhs = zer[n] - zer[i];
      ans = min(ans, lhs + max(rhs - lhs, 0));
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}