#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

char s[sz];

void solve() {
   scanf("%s", s);
   int n = strlen(s);
   int d[10] = {};
   for(int i=0; i<n; i++) d[s[i] - '0']++;
   int ans = 0;
   for(int i=0; i<10; i++) ans = max(ans, d[i]);
   ans = n - ans;

   for(int i=0; i<10; i++) {
      for(int j=0; j<10; j++) {
         if(i == j) continue;
         int res = 0;
         for(int k=0; k<n; k++) {
            if(res & 1) {
               if(s[k] == '0' + i) res++;
            }
            else {
               if(s[k] == '0' + j) res++;
            }
         }
         if(res & 1) res--;
         ans = min(ans, n - res);
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}