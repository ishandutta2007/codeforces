#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

void solve() {
   int a, b;
   scanf("%d %d", &a, &b);
   int ans = INT_MAX;
   for(int i=0; i<100; i++) {
      int x = b + i, n = a, now = i;
      if(x <= 1) continue;
      while(n) n /= x, now++;
      ans = min(ans, now);
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}