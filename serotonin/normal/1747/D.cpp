#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz], c[sz], rc[sz];
ll cum[sz];

int main() {
   int n, q;
   scanf("%d %d", &n, &q);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=1; i<=n; i++) c[i] = a[i] ^ c[i - 1];
   for(int i=n; i; i--) rc[i] = a[i] ^ rc[i + 1];

   for(int i=1; i<=n; i++) cum[i] = cum[i-1] + a[i];

   map <int, set<int>> lhs[2];
   for(int i=1; i<=n; i++) lhs[i & 1][c[i]].insert(i);

   map <int, set<int>> rhs[2];
   for(int i=1; i<=n; i++) rhs[i & 1][rc[i]].insert(-i);
   
   while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);

      ll sum = cum[r] - cum[l - 1];
      if(!sum) {
         puts("0");
         continue;
      }

      int pp = c[r] ^ c[l - 1];
      if(pp) {
         puts("-1");
         continue;
      }

      int d = r - l + 1;
      if(d & 1) {
         puts("1");
         continue;
      }

      if(!a[l] or !a[r]) {
         puts("1");
         continue;
      }

      bool two = 0;
      if(lhs[l & 1].find(c[l - 1]) != lhs[l & 1].end()) {
         auto &st = lhs[l & 1][c[l - 1]];
         auto it = st.upper_bound(l);
         if(it != st.end() and *it < r) two = 1;
      }
      if(rhs[r & 1].find(rc[r + 1]) != rhs[r & 1].end()) {
         auto &st = rhs[r & 1][rc[r + 1]];
         auto it = st.upper_bound(-r);
         if(it != st.end() and *it < -l) two = 1;
      }

      puts(two ? "2" : "-1");
   }
}