#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int a[sz], co, ct, n, one[sz], two[sz];
ll sone[sz], stwo[sz];

ll fnc(int c) {
   ll ans = 0;
   for(int i=0; i<=min(c, co); i++) {
      int j = (c - i) >> 1;
      ans = max(ans, sone[i] + stwo[min(j, ct)]);
   }
   return ans;
}

void solve() {
   int m;
   scanf("%d %d", &n, &m);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   co = 0, ct = 0;
   ll sum = 0;
   for(int i=0; i<n; i++) {
      int p;
      scanf("%d", &p);
      if(p == 1) one[++co] = a[i];
      else two[++ct] = a[i];
      sum += a[i];
   }
   if(sum < m) {
      puts("-1");
      return;
   }

   sort(one + 1, one + co + 1, greater<int>());
   sort(two + 1, two + ct + 1, greater<int>());
   for(int i=1; i<=co; i++) sone[i] = sone[i-1] + one[i];
   for(int i=1; i<=ct; i++) stwo[i] = stwo[i-1] + two[i];

   int lo = 0, hi = n << 1;
   while(lo < hi) {
      int md = lo + hi >> 1;
      if(fnc(md) < m) lo = md + 1;
      else hi = md;
   }
   printf("%d\n", lo);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}