#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   int ans = n - 1, ten = 1;
   while(ten <= n) {
      ans = min(ans, n - ten);
      ten = ten * 10;
   }
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}