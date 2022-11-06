#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int a[sz];
vector <int> g[sz];

void solve() {
   for(int i=0; i<sz; i++) g[i].clear();
   int n;
   scanf("%d", &n);
   for(int i=0; i<n; i++) scanf("%d", &a[i]);
   for(int i=0; i<n; i++) g[a[i]].push_back(i);
   int ans = -1;
   for(int i=0; i<sz; i++) {
      if(g[i].size() < 2) continue;
      for(int j=1; j<g[i].size(); j++) {
         int l = g[i][j-1], r = n - g[i][j];
         ans = max(ans, l + r);
      }
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}