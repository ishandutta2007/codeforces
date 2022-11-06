#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 4e5+7;

int a[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   map <int,vector<int>> mp;
   for(int i=1; i<=n; i++) mp[a[i]].push_back(i);

   tuple <int,int,int,int> ans = {1, a[1], 1, 1};
   for(auto &[x, vec] : mp) {
      int k = 0, pcum = sz, j = 0;
      for(int i : vec) {
         k++;
         int cum = k - (i - k);
         int d = cum - pcum + 1;
         tuple <int,int,int,int> now = {d, x, j, i};
         ans = max(ans, now);
         if(cum < pcum) pcum = cum, j = i;
      }
   }
   auto [d, x, l, r] = ans;
   printf("%d %d %d\n", x, l, r);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}