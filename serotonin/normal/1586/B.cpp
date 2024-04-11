#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 3e5+7;

bool done[sz];

void solve() {
   int n, m;
   scanf("%d %d", &n, &m);
   for(int i=1; i<=n; i++) done[i] = 0;
   while(m--) {
      int u, x, v;
      scanf("%d %d %d", &u, &x, &v);
      done[x] = 1;
   }
   for(int i=1; i<=n; i++) if(!done[i]) {
      for(int j=1; j<=n; j++) if(j ^ i) printf("%d %d\n", i, j);
      break;
   }
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}