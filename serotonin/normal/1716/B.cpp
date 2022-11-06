#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   printf("%d\n", n);
   for(int i=1; i<=n; i++) printf("%d ", a[i] = i); puts("");
   for(int k=1; k<n; k++) {
      swap(a[k], a[k + 1]);
      for(int i=1; i<=n; i++) printf("%d ", a[i]); puts("");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}