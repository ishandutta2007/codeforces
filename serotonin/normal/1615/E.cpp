#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int n, st, beg[sz], fin[sz], par[sz], who[sz], dep[sz], ex[sz*4];
vector <int> g[sz];
pair <int,int> zer[sz*4];
bool done[sz];

void go(int u, int p) {
   beg[u] = ++st; who[st] = u;
   dep[u] = dep[p] + 1; par[u] = p;
   for(int v : g[u]) if(v ^ p) go(v, u);
   fin[u] = st;
}

void init(int u = 1, int b = 1, int e = n) {
   if(b == e) {
      zer[u] = {dep[who[e]], who[e]};
      return;
   }
   int m = b + e >> 1, x = u << 1, y = x + 1;
   init(y, m+1, e); init(x, b, m);
   zer[u] = max(zer[x], zer[y]);
}

void push(int u, int b, int e) {
   zer[u].first += ex[u];
   if(b ^ e) ex[u << 1] += ex[u], ex[u << 1 | 1] += ex[u];
   ex[u] = 0;
}

void update(int l, int r, int w, int u = 1, int b = 1, int e = n) {
   if(ex[u]) push(u, b, e);
   if(e < l || r < b || l > r) return;
   if(l <= b && e <= r) {
      ex[u] += w;
      return push(u, b, e);
   }
   int m = b + e >> 1, x = u << 1, y = x + 1;
   update(l, r, w, x, b, m);
   update(l, r, w, y, m+1, e);
   zer[u] = max(zer[x], zer[y]);
}

int main() {
   int k;
   cin >> n >> k;
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }

   int leaf = 0;
   for(int i=2; i<=n; i++) leaf += g[i].size() == 1;

   if(leaf <= k) {
      ll ans = 0;
      for(int i=leaf; i<=k; i++) {
         ans = max(ans, (ll) i * (n - i));
      }
      cout << ans;
      return 0;
   }

   go(1, 0);

   init();

   int blue = n;
   for(int i=0; i<k; i++) {
      int u = zer[1].second;
      while(u and !done[u]) {
         int l = beg[u], r = fin[u];
         update(l, r, -1);
         done[u] = 1;
         u = par[u];
         blue--;
      }
   }
   ll ans = LLONG_MAX, red = k;
   for(int i=0; i<=blue; i++) {
      ll white = n - red - i;
      ans = min(ans, white * (red - i));
   }
   cout << ans;
}