#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4005;

int n, d[sz], a[sz];

void ask(int u) {
   printf("? %d\n", u); fflush(stdout);
   for(int i=1; i<=n; i++) scanf("%d", &d[i]);
}

set <int> g[sz];

int main() {
   cin >> n;
   ask(1);

   int odd = 0;
   for(int i=1; i<=n; i++) {
      if(d[i] & 1) odd++;
      a[i] = d[i];
      for(int j=1; j<=n; j++) if(d[j] == 1) {
         g[1].insert(j);
      }
   }

   if(odd * 2 < n) {
      for(int i=1; i<=n; i++) {
         if(a[i] & 1) {
            ask(i);
            for(int j=1; j<=n; j++) if(d[j] == 1) {
               g[i].insert(j);
               g[j].insert(i);
            }
         }
      }
   }
   else {
      for(int i=2; i<=n; i++) {
         if(~a[i] & 1) {
            ask(i);
            for(int j=1; j<=n; j++) if(d[j] == 1) {
               g[i].insert(j);
               g[j].insert(i);
            }
         }
      }
   }

   puts("!");
   for(int i=1; i<=n; i++) {
      for(int j : g[i]) {
         if(i < j) printf("%d %d\n", i, j);
      }
   }
   fflush(stdout);
}