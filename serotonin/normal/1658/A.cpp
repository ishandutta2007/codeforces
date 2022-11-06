#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e6+5;

char s[sz];

void solve() {
   int n;
   scanf("%d %s", &n, s);
   int l = -1, ans = 0;
   for(int i=0; i<n; i++) {
      if(s[i] == '0') {
         if(l >= 0) {
            int d = i - l - 1;
            ans += max(0, 2 - d);
         }
         l = i;
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}