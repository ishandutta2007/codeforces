#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e6+5;

int a[sz], xcum[sz];
ll cum[sz];

ll fnc(int l, int r) {
   ll ans = cum[r] - cum[l - 1];
   ans -= xcum[r] ^ xcum[l - 1];
   return ans;
}

void solve() {
   int n, q;
   scanf("%d %d", &n, &q);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);
   
   for(int i=1; i<=n; i++) xcum[i] = a[i] ^ xcum[i - 1];
   for(int i=1; i<=n; i++) cum[i] = a[i] + cum[i - 1];

   while(q--) {
      int l, r;
      scanf("%d %d", &l, &r);
      
      ll ans = fnc(l, r);

      int lo = 1, hi = r - l + 1;
      while(lo < hi) {
         bool yes = 0;
         int md = lo + hi >> 1;
         for(int i = l; ; i++) {
            int j = i + md - 1;
            if(j > r) break;
            if(fnc(i, j) == ans) {
               yes = 1;
               break;
            }
         }
         if(yes) hi = md;
         else lo = md + 1;
      }
      
      for(int i = l; ; i++) {
         int j = i + lo - 1;
         if(fnc(i, j) == ans) {
            printf("%d %d\n", i, j);
            break;
         }
      }
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}