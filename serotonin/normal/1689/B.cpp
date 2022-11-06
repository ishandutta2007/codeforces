#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz], ans[sz];
bool done[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   if(n == 1) {
      puts("-1");
      return;
   }

   for(int i=1; i<=n; i++) done[i] = 0;
   for(int i=1; i<=n; i++) {
      ans[i] = 0;
      for(int j=1; j<=n; j++) if(!done[j] and j != a[i]) {
         ans[i] = j;
         done[j] = 1;
         break;
      }
      if(!ans[i]) ans[i] = ans[i-1], ans[i-1] = a[i];
   }
   for(int i=1; i<=n; i++) printf("%d ", ans[i]); puts("");
}

int main() {
   int t; 
   cin >> t;
   while(t--) solve();
}