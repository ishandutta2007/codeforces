#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];

void solve() {
   scanf("%s", s);
   int n = strlen(s);
   int ans = 0;
   for(int i=1; i<n; i++) {
      if(s[i] == s[i-1]) {
         ans++;
         s[i] = 0;
         continue;
      }
      if(i > 1 && s[i] == s[i-2]) {
         ans++;
         s[i] = 0;
         continue;
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}