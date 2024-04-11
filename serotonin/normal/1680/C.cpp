#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int z[sz];
char s[sz];

void solve() {
   scanf("%s", s + 1);
   int n = strlen(s + 1);
   for(int i=1; i<=n; i++) z[i] = z[i-1] + (s[i] == '0');
   
   int ans = n - z[n], one = 0;
   for(int i=n; i; i--) {
      int zer = z[i];
      ans = min(ans, max(one, zer));
      if(one >= zer) break;

      int j = zer - one;
      if(j < i) ans = min(ans, max(one + j - z[j], z[i] - z[j]));

      one += s[i] == '1';
   }
   ans = min(ans, z[n]);
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}