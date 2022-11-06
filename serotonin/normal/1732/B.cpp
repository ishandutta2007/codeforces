#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e6+5;

char s[sz];
int zer[sz], one[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s + 1);

   reverse(s + 1, s + n + 1);

   for(int i=1; i<=n; i++) {
      if(s[i] == '1') {
         one[i] = one[i - 1];
         zer[i] = 1 + one[i - 1];
      }
      else {
         zer[i] = zer[i - 1];
         one[i] = 1 + zer[i - 1];
      }
   }

   int ans = min(one[n], zer[n]);
   for(int i=n; i; i--) {
      if(s[i] == '1') break;
      ans = min(ans, one[i - 1]);
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}