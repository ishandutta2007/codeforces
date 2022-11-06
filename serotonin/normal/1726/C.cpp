#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e6+5;

int n, a[sz];
char s[sz];
vector <int> g[sz], gg[sz];
bool vis[sz];

void fnc(int l, int r) {
   if(l > r) return;
   int x = a[l] - 1;
   int m = *lower_bound(g[x].begin(), g[x].end(), l + 1);
   gg[l].push_back(m);
   gg[m].push_back(l);
   if(m < r) {
      gg[l].push_back(m + 1);
      gg[m + 1].push_back(l);
   }
   fnc(l + 1, m - 1);
   fnc(m + 1, r);
}

void dfs(int u) {
   vis[u] = 1;
   for(int v : gg[u]) if(!vis[v]) dfs(v);
}

void solve() {
   int n;
   scanf("%d", &n);
   n <<= 1;
   scanf("%s", s + 1);
   for(int i=0; i<=n; i++) g[i].clear(), gg[i].clear(), vis[i] = 0;
   for(int i=1; i<=n; i++) {
      if(s[i] == '(') a[i] = 1;
      else if(s[i] == ')') a[i] = -1;
      a[i] += a[i-1];
      g[a[i]].push_back(i);
   }
   fnc(1, n);

   int ans = 0;
   for(int i=1; i<=n; i++) if(!vis[i]) {
      ans++;
      dfs(i);
   }
   printf("%d\n", ans);
}

int main() {
   int t; cin >> t;
   while(t--) solve();
}