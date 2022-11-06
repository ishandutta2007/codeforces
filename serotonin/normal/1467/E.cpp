#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+5;

int a[sz], w[sz], cnt[sz], ans;
vector <int> g[sz];
map <int,int> mp[sz], tot;

void dfs(int u, int p) {
   w[u] = u;
   for(int v : g[u]) if(v ^ p) {
      dfs(v, u);
      if(mp[w[v]].size() > mp[w[u]].size()) w[u] = w[v];
      if(mp[w[v]].find(a[u]) != mp[w[v]].end()) cnt[1]++, cnt[v]--;
   }
   int x = w[u];
   mp[x][a[u]]++;
   for(int v : g[u]) if(v ^ p) {
      if(w[v] == x) continue;
      for(auto &p : mp[w[v]]) mp[x][p.first] += p.second;
   }
   if(tot[a[u]] > mp[x][a[u]]) cnt[u]++;
}

void down(int u, int p) {
   if(!cnt[u]) ans++;
   for(int v : g[u]) if(v ^ p) cnt[v] += cnt[u], down(v, u);
}

int main() {
   int n;
   cin >> n;
   for(int i=1; i<=n; i++) scanf("%d", &a[i]), tot[a[i]]++;
   for(int i=1; i<n; i++) {
      int u, v;
      scanf("%d %d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
   }
   dfs(1, 0);
   down(1, 0);
   cout << ans;
}