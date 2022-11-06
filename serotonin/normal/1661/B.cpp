#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1<<15;

bool vis[sz];
int ans[sz];

void solve() {
   int n;
   scanf("%d", &n);
   printf("%d ", ans[n]);
}
   
queue <int> q;

void add(int x, int d) {
   x %= sz;
   if(!vis[x]) {
      vis[x] = 1;
      q.push(x);
      ans[x] = d;
   }
}

int main() {
   q.push(0); vis[0] = 1;
   while(!q.empty()) {
      int u = q.front(); q.pop();
      int d = ans[u] + 1;
      
      add(u - 1 + sz, d);

      if(~u & 1) {
         int y = u >> 1, z = y + (sz >> 1);
         add(y, d), add(z, d);
      }
   }

   int t;
   cin >> t;
   while(t--) solve();
}