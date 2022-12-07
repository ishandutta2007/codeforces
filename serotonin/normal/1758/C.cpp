#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n, x;
   scanf("%d %d", &n, &x);
   if(n % x) {
      puts("-1");
      return;
   }
   for(int i=1; i<=n; i++) a[i] = i;
   a[1] = x, a[x] = n, a[n] = 1;
   for(int i=x+1; i<n; i++) {
      if(i % x == 0 and n % i == 0) {
         swap(a[x], a[i]);
         x = i;
      }
   }
   for(int i=1; i<=n; i++) printf("%d ", a[i]); puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}