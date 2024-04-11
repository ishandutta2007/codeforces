#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 2e5+7;

vector <int> g[sz], ara;
vector <vector<int>> ans;

void dfs(int u) {
   ara.push_back(u);
   for(int v : g[u]) dfs(v);
   if(g[u].empty()) {
      ans.push_back(ara);
      ara.clear();
   }
}

void solve() {
   int n, rt;
   scanf("%d", &n);
   for(int i=1; i<=n; i++) g[i].clear();
   for(int i=1, j; i<=n; i++) {
      scanf("%d", &j);
      if(i == j) rt = j;
      else g[j].push_back(i);
   }
   ans.clear(), ara.clear();
   dfs(rt);
   printf("%d\n", ans.size());
   for(auto &vec : ans) {
      printf("%d\n", vec.size());
      for(int &x : vec) printf("%d ", x);
      puts("");
   }
   puts("");
}

int main() {
   int t;
   cin >> t;
   while(t--) solve();
}