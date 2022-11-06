#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[sz];
bool zer[sz], one[sz];

void solve() {
   scanf("%s", s + 1);
   int n = strlen(s + 1);
   for(int i=1; i<=n; i++) {
      zer[i] = zer[i-1];
      if(s[i] == '0') zer[i] = 1;
   }
   one[n+1] = 0;
   for(int i=n; i; i--) {
      one[i] = one[i+1];
      if(s[i] == '1') one[i] = 1;
   }
   
   int ans = 0;
   for(int i=1; i<=n; i++) {
      if(!zer[i-1] and !one[i+1]) ans++;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}