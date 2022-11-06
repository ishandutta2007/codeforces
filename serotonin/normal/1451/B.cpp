#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

char s[sz];

void solve() {
   int n, q;
   scanf("%d %d %s", &n, &q, s);
   while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      l--, r--;
      bool yes = 0;
      for(int c=0; c<n; c++) {
         int i=0, j=l;
         for(i=0; i<n && j<=r; i++) {
            if(i == c) {
               if(j == l) break;
               continue;
            }
            if(s[i] == s[j]) j++;
         }
         if(i > c && j > r) {
            yes = 1;
            break;
         }
      }
      if(yes) puts("YES");
      else puts("NO");
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}