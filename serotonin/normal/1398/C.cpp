#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

char s[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s);
   map <int,int> mp;
   mp[0]++;
   ll ans = 0;
   for(int i=0, j=0; s[i]; i++) {
      j += s[i] - '0' - 1;
      ans += mp[j];
      mp[j]++;
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}