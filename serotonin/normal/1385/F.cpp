#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

typedef pair <int, int> pii;
#define x first
#define y second

int a[sz], cut[sz], done[sz];
vector <int> g[sz];
queue <int> lg[sz];

void solve() {
   int n, k;
   cin >> n >> k;
   for(int i=1; i<=n; i++) {
      g[i].clear(), a[i] = cut[i] = done[i] = 0;
      while(!lg[i].empty()) lg[i].pop();
   }
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   priority_queue <pii> pq;
   for(int i=1; i<=n; i++) if(g[i].size() == 1) a[g[i][0]]++, lg[g[i][0]].push(i);
   for(int i=1; i<=n; i++) if(a[i]) pq.emplace(a[i], i);

   int ans = 0;
   while(!pq.empty()) {
      pii p = pq.top(); pq.pop();
      int u = p.y, c = p.x;
//      printf("%d\n", u);
      if(a[u] ^ c || done[u]) continue;
//      printf("%d\n", u);
      if(c < k) break;
//      printf("%d\n", u);
      c -= k, a[u] = c, cut[u] += k;
      for(int i=0; i<k; i++) done[lg[u].front()] = 1, lg[u].pop();
      if(a[u]) pq.emplace(a[u], u);
      if(cut[u] + 1 == g[u].size()) {
         for(int v : g[u]) if(!done[v]) lg[v].push(u), a[v]++, pq.emplace(a[v], v);
      }
      ans++;
//      printf("%d\n", ans);
   }

   printf("%d\n", ans);
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}