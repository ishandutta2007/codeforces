#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char s[sz];

void solve() {
   int x;
   scanf("%d", &x);
   for(int i=0, j=0; ; j++) {
      i += j;
      if(i == x) {
         printf("%d\n", j);
         return;
      }
      if(i > x) {
         i -= x;
         if(i > 1) printf("%d\n", j);
         else printf("%d\n", j + 1);
         return;
      }
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}