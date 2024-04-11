#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+5;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   map <int,int> mp;
   for(int i=0; i<n; i++) {
      int x;
      scanf("%d", &x);
      mp[x]++;
   }
   int ans = n, z = mp.size(), cut = 0;
   vector <int> ara;
   for(auto it : mp) ara.push_back(it.second);
   sort(ara.begin(), ara.end());
   for(int x : ara) {
      int now = cut + (n - cut) - z * x;
      ans = min(ans, now);
      z--;
      cut += x;
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}