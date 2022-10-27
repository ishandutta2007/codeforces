#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int n, a[N], b[N], deg[N], dep[N];
vector<int> g[N];
bool vis[N];
LL dp[N];

bool cmp(int x,int y) {
	return dep[x] > dep[y];
}

void dfs(int u) {
	vis[u] = 1;
	dp[u] = a[u];
	for (auto v: g[u]) {
		dep[v] = dep[u] + 1;
		dfs(v); 
		if (dp[v] > 0) {
			dp[u] += dp[v];
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &b[i]);
		if (b[i] != -1) {
			g[b[i]].push_back(i); deg[i] ++;
		}
	}
	for (int i = 1; i <= n; i ++) {
		if (deg[i] == 0) {
			dfs(i);
		}
	}
	LL res = 0;
	for (int i = 1; i <= n; i ++) {
		res += dp[i];
	}
	memset(vis,0,sizeof(vis));
	printf("%lld\n", res);

	int p[N];
	for (int i = 1; i <= n; i ++) p[i] = i;
	sort(p + 1, p + 1 + n, cmp);
	
	vector<int> ans;
	for (int i = 1; i <= n; i ++) {
		int u = p[i];
		if (dp[u] <= 0 || dep[u] == 0) {
			queue<int> q; q.push(u);
			while(q.size()) {
				int x=q.front(); q.pop(); ans.push_back(x);
				for (auto y: g[x]) {
					if(dp[y]>0)
					q.push(y);
				}
			}
		}
	}
	reverse(ans.begin(), ans.end());
	for(int i=0;i<ans.size();i++){
		printf("%d ", ans[i]);
	}

}