#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

void solve() {
   int n, k;
   scanf("%d %d", &n, &k);
   map <int,int> mx, mn;
   for(int i=1; i<=n; i++) {
      int x;
      scanf("%d", &x);
      if(!mx[x]) mx[x] = mn[x] = i;
      else mx[x] = max(mx[x], i), mn[x] = min(mn[x], i);
   }
   while(k--) {
      int u, v;
      scanf("%d %d", &u, &v);
      if(mx.find(u) == mx.end() or mx.find(v) == mx.end()) puts("No");
      else {
         u = mn[u], v = mx[v];
         puts(u <= v ? "Yes" : "No");
      }
   }
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}