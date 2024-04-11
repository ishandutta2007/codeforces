#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz];

void solve() {
   int n, h;
   scanf("%d %d", &n, &h);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   sort(a, a+n);
   reverse(a, a+n);

   int x = a[0] + a[1];
   int ans = h / x;
   h -= ans * x; ans *= 2;

   if(h > 0) {
      h -= a[0];
      ans++;
   }

   if(h > 0) ans++;

   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}