#include<bits/extc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int n, a[sz], bit[sz];

void add(int x) {
   while(x <= n) {
      bit[x]++;
      x += x & -x;
   }
}

int quer(int x) {
   int res = 0;
   while(x) {
      res += bit[x];
      x -= x & -x;
   }
   return res;
}

void solve() {
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), bit[i] = 0;
   int ans = 0;
   for(int i=1; i<=n; i++) {
      add(a[i]);
      ans += quer(i) == i;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}