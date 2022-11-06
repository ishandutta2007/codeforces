#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

char a[sz], b[sz];

void solve() {
   scanf("%s %s", a, b);
   int na = strlen(a), nb = strlen(b);

   for(int i=0, k=0; i<max(na, nb); i++) {
      for(int j=0; j<na; j++, k++) {
         if(k == nb) k = 0;
         if(a[j] ^ b[k]) {
            puts("-1");
            return;
         }
      }
      if(k == nb) k = 0;
      if(k == 0) {
         int t = i+1;
         while(t--) printf("%s", a);
         puts("");
         return;
      }
   }
   puts("-1");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}