#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

typedef pair <int, int> pii;
#define x first
#define y second

bitset <sz> vis;
vector <int> l, r;
vector <pii> g[sz];
int ea[sz], eb[sz], cnt[sz];

void dfs(int u, int p = 0) {
   if(vis[u]) return;
   vis[u] = 1;
   for(auto d : g[u]) {
      if(d.x == p) {
         p = 0;
         continue;
      }
      if(d.y < 0) l.push_back(-d.y);
      else r.push_back(d.y);
      dfs(d.x, u);
      break;
   }
}

void solve() {
   int n;
   cin >> n;
   for(int i=1; i<=n; i++) g[i].clear(), cnt[i] = vis[i] = 0;
   for(int i=1; i<=n; i++) scanf("%d", &ea[i]);
   for(int i=1; i<=n; i++) scanf("%d", &eb[i]);
   for(int i=1; i<=n; i++) {
      int u = ea[i], v = eb[i];
      cnt[u]++, cnt[v]++;
      g[u].emplace_back(v, i);
      g[v].emplace_back(u, -i);
   }
   for(int i=1; i<=n; i++) if(cnt[i] > 2) {
      puts("-1");
      return;
   }

   vector <int> ans;
   for(int i=1; i<=n; i++) {
      if(vis[i]) continue;
      l.clear(), r.clear();
      dfs(i);
      if(l.size() < r.size()) for(int x : l) ans.push_back(x);
      else for(int x : r) ans.push_back(x);
   }

   printf("%d\n", ans.size());
   for(int x : ans) printf("%d ", x);
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}