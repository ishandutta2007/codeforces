#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

ll a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%lld", &a[i]);

   for(int i=0; i<n; i++) {
      if(a[i] < i) {
         puts("NO");
         return;
      }
      a[i+1] += a[i] - i;
   }
   puts("YES");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}