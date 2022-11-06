#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e6+5;

int a[sz], c[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=1; i<=n; i++) c[i] = c[i - 1] + (i & 1 ? a[i] : -a[i]);

   if(c[n] & 1) {
      puts("-1");
      return;
   }

   if(!c[n]) {
      puts("1");
      printf("1 %d\n", n);
      return;
   }

   vector <pair <int,int>> ans;
   for(int i=1; i<=n; i++) {
      int l = i, r = l, c = 0, s = 0;
      while(1) {
         if(a[r]) c++;
         if((r - l + 1) & 1) s += a[r];
         else s -= a[r];
         if(c == 2) break;
         r++;
      }
      i = r;
      if(!s) ans.emplace_back(l, r);
      else {
         ans.emplace_back(l, l);
         ans.emplace_back(l + 1, r);
      }
   }

   printf("%d\n", ans.size());
   for(auto [l, r] : ans) printf("%d %d\n", l, r);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}