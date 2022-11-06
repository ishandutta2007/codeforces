#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

int a[sz], rhs[sz];
bool vis[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) scanf("%d", &a[i]);

   for(int i=0; i<=n; i++) vis[i] = 0;

   int j = 0;
   for(int i=n; i; i--) {
      vis[a[i]] = 1;
      while(vis[j]) j++;
      rhs[i] = j;
   }

   vector <int> ans;
   int r = 1;
   while(r <= n) {
      int mx = rhs[r];
      ans.push_back(mx);
      for(int i=0; i<=mx; i++) vis[i] = 0;
      j = 0;
      if(!mx) r++;
      while(j < mx) {
         vis[a[r++]] = 1;
         while(vis[j]) j++;
      }
   }
   printf("%d\n", ans.size());
   for(int x : ans) printf("%d ", x); puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}