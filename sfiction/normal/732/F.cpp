#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 4E5 + 10, MAXM = 4E5 + 10;

int n, m;
vector<PII> E[MAXN], F[MAXN];
int dfn[MAXN], low[MAXN];
int tot;
int fa[MAXN];

int e[MAXM][2];
int mark[MAXN];

int find(int x){
	return fa[x] < 0 ? x : (fa[x] = find(fa[x]));
}

void DFS(int u, int pre){
	dfn[u] = low[u] = ++tot;
	for (int v, i = 0; i < E[u].size(); ++i){
		if (mark[E[u][i].nd])
			continue;

		int t = E[u][i].nd;
		if (e[t][0] != u)
			swap(e[t][0], e[t][1]);

		mark[E[u][i].nd] = 1;
		v = E[u][i].st;
		if (dfn[v] == 0){
			DFS(v, u);
			if (low[v] > dfn[u])
				mark[E[u][i].nd] = 2;
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}

int val;

void DFS2(int u, int pre){
	dfn[u] = 1;
	if (fa[val] > fa[u])
		val = u;
	for (int v, i = 0; i < F[u].size(); ++i){
		if ((v = F[u][i].st) == pre)
			continue;
		DFS2(v, u);
	}
}

void DFS3(int u, int pre){
	for (int v, i = 0; i < F[u].size(); ++i){
		if ((v = F[u][i].st) == pre)
			continue;

		int t = F[u][i].nd;
		if (find(e[t][0]) == u)
			swap(e[t][0], e[t][1]);
		DFS3(v, u);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		e[i][0] = u, e[i][1] = v;
		E[u].push_back(PII(v, i));
		E[v].push_back(PII(u, i));
	}
	DFS(1, 0);
	fill_n(fa + 1, n, -1);
	for (int i = 0; i < m; ++i){
		int u = find(e[i][0]), v = find(e[i][1]);
		if (mark[i] != 2 && u != v)
			fa[u] += fa[v], fa[v] = u;
	}
	for (int i = 0; i < m; ++i)
		if (mark[i] == 2){
			int u = find(e[i][0]), v = find(e[i][1]);
			F[u].push_back(PII(v, i));
			F[v].push_back(PII(u, i));
		}
	fill_n(dfn + 1, n, 0);
	int ans = n;
	for (int i = 1; i <= n; ++i)
		if (fa[i] < 0 && !dfn[i]){
			val = i;
			DFS2(i, 0);
			DFS3(val, 0);
			ans = min(ans, -fa[val]);
		}
	printf("%d\n", ans);
	for (int i = 0; i < m; ++i)
		printf("%d %d\n", e[i][0], e[i][1]);
	return 0;
}