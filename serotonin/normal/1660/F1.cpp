#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

char s[sz];
int cum[sz];

void solve() {
   int n, ans = 0;
   scanf("%d %s", &n, s + 1);
   for(int i=1; i<=n; i++) {
      cum[i] = s[i] == '+' ? 1 : -1;
      cum[i] += cum[i-1];
   }
   for(int i=1; i<=n; i++) {
      for(int j=i; j<=n; j++) {
         int sum = cum[j] - cum[i-1];
         if(sum <= 0 and sum % 3 == 0) ans++;
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}