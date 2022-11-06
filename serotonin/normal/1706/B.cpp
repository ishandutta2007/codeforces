#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e5+5;

vector <int> g[sz];

void solve() {
   int n;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) g[i].clear();
   for(int i=1; i<=n; i++) {
      int x;
      scanf("%d", &x);
      g[x].push_back(i);
   }
   for(int i=1; i<=n; i++) {
      if(g[i].empty()) printf("0 ");
      else {
         int x = g[i][0] & 1, cnt = 0;
         for(int v : g[i]) if((v & 1) == x) {
            x ^= 1;
            cnt++;
         }
         printf("%d ", cnt);
      }
   }
   puts("");
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}