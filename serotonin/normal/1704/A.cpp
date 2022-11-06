#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+6;

char a[sz], b[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   scanf("%s %s", a, b);
   if(n < m) {
      puts("No");
      return;
   }
   int d = n - m + 1;
   bool zer = 0, one = 0;
   for(int i=0; i<d; i++) {
      if(a[i] == '0') zer = 1;
      if(a[i] == '1') one = 1;
   }
   if(b[0] == '0' and !zer) {
      puts("No");
      return;
   }
   if(b[0] == '1' and !one) {
      puts("No");
      return;
   }

   for(int i=d, j=1; i<n; i++, j++) {
      if(a[i] != b[j]) {
         puts("No");
         return;
      }
   }
   puts("Yes");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}