#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 2E5 + 10;

int n;
int val[MAXN];
vector<int> E[MAXN];
int m[MAXN][2];

void DFS1(int u, int pre){
	m[u][0] = m[u][1] = 0;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i]) == pre)
			continue;
		DFS1(v, u);
		int t = m[v][0] + (val[u] ^ val[v]);
		if (m[u][0] < t)
			m[u][1] = m[u][0], m[u][0] = t;
		else if (m[u][1] < t)
			m[u][1] = t;
	}
}

int ans;

void DFS2(int u, int pre, int up){
	ans = min(ans, max(m[u][0], up));
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i]) == pre)
			continue;
		int t = val[u] ^ val[v];
		DFS2(v, u, max(up, m[u][m[u][0] == m[v][0] + t]) + t);
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", val + i);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS1(1, 0);
	ans = n;
	DFS2(1, 0, 0);
	printf("%d\n", ans);
}