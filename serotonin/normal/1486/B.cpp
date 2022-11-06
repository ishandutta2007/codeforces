#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz], b[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d %d", &a[i], &b[i]);
   if(n & 1) {
      puts("1");
      return;
   }

   sort(a, a+n);
   sort(b, b+n);
   n >>= 1;
   ll x = a[n] - a[n-1] + 1;
   ll y = b[n] - b[n-1] + 1;
   printf("%lld\n", x * y);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}