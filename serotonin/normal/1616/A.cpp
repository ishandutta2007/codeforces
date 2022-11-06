#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 205;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   memset(a, 0, sizeof a);
   for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      a[abs(x)]++;
   }
   int ans = 0;
   for(int i=1; i<sz; i++) ans += min(a[i], 2);
   ans += a[0] > 0;
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}