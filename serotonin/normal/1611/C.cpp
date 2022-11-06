#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   if(a[1] == n) {
      reverse(a + 2, a + n + 1);
      for(int i=1; i<=n; i++) printf("%d ", a[i]);
      puts("");
   }
   else if(a[n] == n) {
      reverse(a + 1, a + n);
      for(int i=1; i<=n; i++) printf("%d ", a[i]);
      puts("");
   }
   else puts("-1");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}