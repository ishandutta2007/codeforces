#include <bits/stdc++.h>
using namespace std;
#define M 200010

typedef long long LL;
typedef pair <int, int> PII;

vector <PII> v[M];
int dp[M], pa[20][M], T, n, dt[M];
LL cost[M];

void dfs(int x) {
  dt[x] = ++T;
  for (int i = 0; i < v[x].size(); i++) {
    int u = v[x][i].first, c = v[x][i].second;
    if (u == pa[0][x]) continue;
    cost[u] = cost[x] + c;
    dp[u] = dp[x] + 1; pa[0][u] = x; dfs(u);
  }
}

int LCA(int i, int j) {
	int k;
	if (dp[i] < dp[j]) i ^= j ^= i ^= j;
	for (k = 0; (1 << k) <= dp[i]; k ++); k --;
	for (int u = k; u >= 0; u --) if (dp[i] - (1 << u) >= dp[j]) i = pa[u][i];
	if (i != j) {
		for (int u = k; u >= 0; u --) if (pa[u][i] != pa[u][j]) i = pa[u][i], j = pa[u][j];
		i = pa[0][i];
	}
	return i;
}


set <PII> setv;
set <PII> :: iterator x, y;

LL ins(int u) {
	if(setv.empty()) return 0;
	x = setv.lower_bound(PII(dt[u], u)), y;
	y = x--;
	if (y == setv.begin() || y == setv.end()) x = setv.begin(), y = --setv.end();
	int l = (*x).second, r = (*y).second;
	return cost[u] - cost[LCA(l, u)] - cost[LCA(r, u)] + cost[LCA(l, r)];
}

int main() {
  //freopen("in.txt", "r", stdin);
  scanf("%d", &n);
  int x, y, z;
  for (int i = 0; i < n - 1; i++) {
    scanf("%d %d %d", &x, &y, &z);
    v[x].push_back(PII(y, z));
    v[y].push_back(PII(x, z));
  }
  dp[1] = 1;
  dfs(1);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) pa[i][j] = pa[i - 1][pa[i - 1][j]];
  }
  int Q;
  char ty[10];
  LL ans = 0;


  for (scanf("%d", &Q); Q--; ) {
    scanf("%s", ty);
    if (ty[0] == '+') {
      scanf("%d", &x);
      PII p = PII(dt[x], x);
      ans += ins(x);
      setv.insert(p);
    }
    else if (ty[0] == '-') {
      scanf("%d", &x);
      PII p = PII(dt[x], x);
      setv.erase(p);
      ans -= ins(x);
    }
    else {
      printf("%I64d\n", ans);
    }
  }
}