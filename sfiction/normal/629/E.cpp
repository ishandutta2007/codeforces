#include <cstdio>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1E5 + 10, MAXM = 1E5 + 10;

int n, m;
vector<int> E[MAXN];
vector<PII> f[MAXN];

ll size[MAXN], size2[MAXN];
ll sum[MAXN], sum2[MAXN];

int dep[MAXN];
int fa[MAXN];

double ans[MAXM];

int find(int x){
	return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void DFS1(int u, int pre){
	size[u] = 1;
	sum[u] = 0;
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre){
			DFS1(v, u);
			size[u] += size[v];
			sum[u] += sum[v];
		}
	sum[u] += size[u] - 1;
}

void DFS2(int u, int pre, int depth){
	dep[u] = depth;
	fa[u] = u;
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre){
			size2[u] = n - size[v];
			sum2[u] = sum2[pre] + size2[pre] + sum[u] - sum[v] - size[v];
			DFS2(v, u, depth + 1);
			fa[v] = u;
		}

	for (int v, i = 0; i < f[u].size(); ++i)
		if (fa[v = f[u][i].st] == f[u][i].st)
			ans[f[u][i].nd] = sum[u] / (double)size[u] + sum2[v] / (double)size2[v] + (dep[u] - dep[v] + 1);
		else if (fa[v] && dep[u] > dep[find(v)])
			ans[f[u][i].nd] = sum[u] / (double)size[u] + sum[v] / (double)size[v] + (dep[u] + dep[v] - dep[find(v)] * 2 + 1);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		f[u].push_back(PII(v, i));
		f[v].push_back(PII(u, i));
	}
	DFS1(1, 0);
	DFS2(1, 0, 1);
	for (int i = 0; i < m; ++i)
		printf("%.12f\n", ans[i]);
	return 0;
}