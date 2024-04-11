#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

int n, p[sz], a[sz], dis[sz];

int ara[sz], kid;
bool done[sz];

struct ds {
   vector <pair<int,int>> mst[sz << 2];

   void init(int u = 1, int b = 1, int e = n) {
      if(b == e) {
         mst[u] = {make_pair(a[b], b)};
         return;
      }
      int md = b + e >> 1, x = u << 1, y = x | 1;
      init(x, b, md), init(y, md + 1, e);
      merge(mst[x].begin(), mst[x].end(), mst[y].begin(), mst[y].end(), back_inserter(mst[u]));
   }

   void query(int l, int r, int w, int u = 1, int b = 1, int e = n) {
      if(e < l or r < b or l > r) return;
      if(l <= b and e <= r) {
         while(!mst[u].empty() and mst[u].back().first >= w) {
            int v = mst[u].back().second; mst[u].pop_back();
            if(!done[v]) ara[++kid] = v;
            done[v] = 1;
         }
         return;
      }
      int md = b + e >> 1, x = u << 1, y = x | 1;
      query(l, r, w, x, b, md);
      query(l, r, w, y, md + 1, e);
   }
} lhs, rhs;

void solve() {
   int s, t;
   scanf("%d %d %d", &n, &s, &t);
   for(int i=1; i<=n; i++) scanf("%d", &p[i]);
   
   int dd = n << 2;
   for(int i=0; i<dd; i++) lhs.mst[i].clear(), rhs.mst[i].clear();

   for(int i=1; i<=n; i++) a[i] = i + p[i];
   lhs.init();
   for(int i=1; i<=n; i++) a[i] = p[i] - i;
   rhs.init();

   for(int i=1; i<=n; i++) dis[i] = n, done[i] = 0;
   queue <int> q; q.push(s);
   dis[s] = 0, done[s] = 1;
   while(!q.empty()) {
      int u = q.front(); q.pop();
      int nd = dis[u] + 1;
      
      int lx = max(1, u - p[u]), rx = u - 1;
      if(lx <= rx) {
         kid = 0;
         lhs.query(lx, rx, u);
         while(kid) {
            int v = ara[kid--];
            if(dis[v] > nd) {
               dis[v] = nd;
               q.push(v);
            }
         }
      }

      lx = u + 1, rx = min(n, u + p[u]);
      if(lx <= rx) {
         kid = 0;
         rhs.query(lx, rx, -u);
         while(kid) {
            int v = ara[kid--];
            if(dis[v] > nd) {
               dis[v] = nd;
               q.push(v);
            }
         }
      }
   }
   printf("%d\n", dis[t]);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}