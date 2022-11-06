#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 5e5+5;

void solve() {
   int n;
   scanf("%d", &n);
   map <int,vector<int>> mp;
   for(int i=1, x; i<=n; i++) scanf("%d", &x), mp[x].push_back(i);
   ll ans = 0;
   for(auto &[vv, ara] : mp) {
      int z = ara.size();
      ll sum = 0;
      for(int x : ara) sum += n - x + 1;
      for(int x : ara) sum -= n - x + 1, ans += x * sum;
   }
   printf("%lld\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}