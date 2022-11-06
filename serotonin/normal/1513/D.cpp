#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz];
bool done[sz];

void solve() {
   int n, p;
   scanf("%d %d", &n, &p);
   map <int,vector<int>> mp;
   for(int i=1; i<=n; i++) {
      scanf("%d", &a[i]);
      if(a[i] < p) mp[a[i]].push_back(i);
      done[i] = 0;
   }
   ll ans = (n - 1LL) * p;
   for(auto &[v, ara] : mp) {
      for(auto &i : ara) {
         if(done[i]) continue;
         done[i] = 1;
         for(int j=i+1; j<=n; j++) {
            if(a[j] % v) break;
            ans += v - p;
            if(done[j]) break;
            done[j] = 1;
         }
         for(int j=i-1; j; j--) {
            if(a[j] % v) break;
            ans += v - p;
            if(done[j]) break;
            done[j] = 1;
         }
      }
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}