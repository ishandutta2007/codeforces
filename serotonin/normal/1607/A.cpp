#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

char s[sz];
int a[sz];

void solve() {
   scanf("%s", s);
   for(int i=0; i<26; i++) a[s[i] - 'a'] = i;
   scanf("%s", s);
   ll ans = 0;
   for(int i=1; s[i]; i++) {
      int x = s[i] - 'a';
      int y = s[i-1] - 'a';
      ans += abs(a[x] - a[y]);
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}