#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

char s[sz];

void solve() {
   int n;
   scanf("%d", &n);
   scanf("%s", s);
   
   ll ans = 0, x = 0;
   for(int i=0; i<n; i++) x += s[i] == '1';
   ans = x * (n - x);

   x = 1;
   for(int i=1; i<n; i++) {
      if(s[i] == s[i-1]) x++;
      else {
         ans = max(ans, x * x);
         x = 1;
      }
   }
   ans = max(ans, x * x);

   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}