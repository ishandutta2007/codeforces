#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   map <int,int> mp;
   for(int i=0; i<n; i++) scanf("%d", &a[i]), mp[a[i]]++;
   
   int c = 0;
   for(auto [m, x] : mp) c = max(c, x);

   int ans = 0;
   while(c < n) {
      ans++;
      int z = min(c << 1, n);
      ans += z - c;
      c = z;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}