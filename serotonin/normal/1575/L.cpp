#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+5;

int n, a[sz], dp[sz], ara[sz], bit[sz];
vector <int> g[sz];

void upd(int x, int v) {
   x++;
   while(x) {
      bit[x] = max(bit[x], v);
      x -= x & -x;
   }
}

int quer(int x) {
   x++;
   int res = 0;
   while(x < sz) {
      res = max(res, bit[x]);
      x += x & -x;
   }
   return res;
}

int main() {
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d", &ara[i]), a[i] = i - ara[i];
   for(int i=1; i<=n; i++) g[ara[i]].push_back(i);

   int ans = 0;
   for(int k=sz-1; k; k--) {
      for(int i : g[k]) {
         if(a[i] < 0) continue;
         dp[i] = 1 + quer(i - ara[i]);
         ans = max(ans, dp[i]);
      }
      for(int i : g[k]) if(a[i] >= 0)
         upd(i - ara[i], dp[i]);
   }
   cout << ans;
}