#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

ll a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
   
   vector <tuple<int,int,int>> ans;
   for(int i=n-2; i; i--) {
      ll now = a[i+1] - a[n];
      if(a[i] > now) {
         ans.emplace_back(i, i+1, n);
         a[i] = now;
      }
   }
   for(int i=2; i<=n; i++) if(a[i] < a[i-1]) {
      puts("-1");
      return;
   }
   printf("%d\n", ans.size());
   for(auto [x, y, z] : ans) printf("%d %d %d\n", x, y, z);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}