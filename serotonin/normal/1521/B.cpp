#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+5, x = 1e9+7, y = 1e9+9;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   int j = min_element(a + 1, a + n + 1) - a;
   printf("%d\n", n - 1);
   for(int i=1; i<=n; i++) {
      if(i == j) continue;
      int p = x;
      if(i & 1) p = y;
      printf("%d %d %d %d\n", i, j, p, a[j]);
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}