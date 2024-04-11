#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

void solve() {
   int n;
   cin >> n;
   ll sum = 0;
   for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      sum += x;
   }
   printf("%lld\n", abs(sum));
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}