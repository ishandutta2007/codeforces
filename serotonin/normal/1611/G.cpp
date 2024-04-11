#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+7;

char s[sz];
set <int> g[sz];
int n, m;

void go(int x, int y) {
   if(x >= n) return;
   int i = x + y;
   auto it = g[i].lower_bound(x);
   if(it == g[i].end()) go(x + 1, y + 1);
   else {
      while(it != g[i].end()) {
         x = *it;
         it = g[i].erase(it);
      }
      y = i - x;
      go(x + 1, y + 1);
   }
}

void solve() {
   scanf("%d %d", &n, &m);
   int deg = n + m;
   for(int i=0; i<deg; i++) g[i].clear();
   for(int i=0; i<n; i++) {
      scanf("%s", s);
      for(int j=0; j<m; j++) if(s[j] == '1') {
         g[i+j].insert(i);
      }
   }

   int ans = 0;
   for(int i=0; i<deg; i++) {
      if(g[i].empty()) continue;
      ans++;
      int x = *g[i].rbegin(), y = i - x;
      go(x + 1, y + 1);
   }
   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}