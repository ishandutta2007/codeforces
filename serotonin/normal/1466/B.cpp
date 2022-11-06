#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];
bitset <sz> done;

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<=2*n+5; i++) done[i] = a[i] = 0;
   for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      a[x]++;
   }
   int ans = 0;
   for(int i=0; i<=2*n+5; i++) {
      if(!done[i] && a[i]) a[i]--, done[i] = 1;
      if(done[i]) ans++;
      if(a[i]) done[i+1] = 1;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}