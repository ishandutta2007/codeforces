#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int c[sz], cnt[sz];

void solve() {
   int n, l, r;
   scanf("%d %d %d", &n, &l, &r);
   for(int i=1; i<=n; i++) cnt[i] = 0;
   for(int i=1; i<=n; i++) {
      scanf("%d", &c[i]);
      if(i <= l) cnt[c[i]]++;
      else cnt[c[i]]--;
   }

   int psum = 0, nsum = 0;
   vector <int> pos, neg;
   for(int i=1; i<=n; i++) {
      if(cnt[i] > 0) pos.push_back(cnt[i]), psum += cnt[i];
      if(cnt[i] < 0) neg.push_back(-cnt[i]), nsum -= cnt[i];
   }

   int ans = 0;
   if(psum > nsum) {
      int dx = psum - nsum;
      ans += nsum;
      for(int &x : pos) {
         int z = min(x / 2, dx / 2);
         dx -= z * 2;
         x -= z * 2;
         ans += z;
      }
      ans += dx;
   }
   else {
      int dx = nsum - psum;
      ans += psum;
      for(int &x : neg) {
         int z = min(x / 2, dx / 2);
         dx -= z * 2;
         x -= z * 2;
         ans += z;
      }
      ans += dx;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}