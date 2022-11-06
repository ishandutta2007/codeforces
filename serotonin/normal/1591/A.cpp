#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

int a[sz];

void solve() {
   int n;
   cin >> n;
   for(int i=0; i<n; i++) scanf("%d", &a[i]);

   int ans = 1;
   for(int i=0; i<n; i++) {
      if(i and !a[i-1] and !a[i]) {
         puts("-1");
         return;
      }
      if(i and a[i] and a[i-1]) ans += 5;
      else if(a[i]) ans++;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}