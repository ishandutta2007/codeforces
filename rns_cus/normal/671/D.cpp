#include <bits/stdc++.h>
using namespace std;
typedef pair <int, int> PII;
typedef long long LL;
#define M 300010

set <PII> s[M];
vector <int> adj[M];

int dp[M], pa[M], n, m, cost[M];
LL ans;

void dfs(int x) {
  for (int i = 0; i < adj[x].size(); i++) {
    int u = adj[x][i];
    if (u == pa[x]) continue;
    pa[u] = x; dp[u] = dp[x] + 1;
    dfs(u);
  }
}

void join(int x, int y){
  if(s[x].size() > s[y].size()) {
    swap(s[x], s[y]); swap(cost[x], cost[y]);
  }
  int d = cost[x] - cost[y];
  for (set <PII> :: iterator it = s[x].begin(); it != s[x].end(); it++) {
    s[y].insert(PII((*it).first + d, (*it).second));
  }
  s[x].clear();
}

int DFS(int x){
  int id = x;
  for (int i = 0; i < adj[x].size(); i++) {
    int u = adj[x][i];
    if (pa[x] == u) continue;
    int t = DFS(u);
    if (dp[t] < dp[id]) id = t;
  }
  if (x == 1) {cout << ans << endl; exit(0);}
  if(id == x) {
    if(s[x].empty()) {
      puts("-1"); exit(0);
    }
    while (dp[(*s[x].begin()).second] >= dp[x]) s[x].erase(s[x].begin());
    PII cur = *s[x].begin(); s[x].erase(cur);
    ans += cost[x] + cur.first;
    cost[x] = -cur.first;
    join(x, cur.second);
    id = cur.second;
  }
  else join(x, id);
  return id;
}

int main(){
  //freopen("D.in", "r", stdin);
  scanf("%d %d", &n, &m);
  int x, y, z;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d", &x, &y);
    adj[x].push_back(y); adj[y].push_back(x);
  }
  dp[0] = n + 1; dfs(1);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &x, &y, &z);
    if (x == y) continue;
    if (dp[x] < dp[y]) swap(x, y);
    s[x].insert(PII(z, y));
  }
  DFS(1);
}