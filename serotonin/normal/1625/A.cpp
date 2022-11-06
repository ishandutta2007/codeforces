#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n, l;
   scanf("%d %d", &n, &l);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   int ans = 0;
   for(int j=0; j<l; j++) {
      int c = 0;
      for(int i=0; i<n; i++) if(a[i] & 1 << j) c++;
      if(c * 2 >= n) ans |= 1 << j;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}