#include <climits>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, vector<int> > PIVI;

const int MAXN = 1E3 + 10, MAXM = 3E4 + 10;

int n, m;
int S, T;
int edge[MAXM][3], edgeId[MAXM];
bool vis[MAXM], mark[MAXM];

int tot, dfn[MAXN], low[MAXN];
int fa[MAXN];
vector<PII> E[MAXN];

vector<int> testLst;

int find(int x){
	return x == fa[x] ? x : (fa[x] = find(fa[x]));
}

bool DFS1(int u){
	if (u == T)
		return true;
	dfn[u] = true;
	for (int v, i = 0; i < E[u].size(); ++i)
		if (!dfn[v = E[u][i].st]){
			testLst.push_back(E[u][i].nd);
			if (DFS1(E[u][i].st))
				return true;
			testLst.pop_back();
		}
	return false;
}

void DFS2(int u){
	dfn[u] = low[u] = ++tot;
	for (int v, i = 0; i < E[u].size(); ++i){
		if (vis[E[u][i].nd])
			continue;
		vis[E[u][i].nd] = true;

		if (!dfn[v = E[u][i].st]){
			DFS2(v);
			if (dfn[u] < low[v])
				mark[E[u][i].nd] = true;
			low[u] = min(low[u], low[v]);
		}
		else
			low[u] = min(low[u], dfn[v]);
	}
}

PIVI solve(int sp){
	fill_n(vis, m, false);
	vis[sp] = true;
	fill_n(mark, m, false);
	fill_n(dfn + 1, n, 0);
	tot = 0;
	DFS2(S);

	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 0; i < m; ++i)
		if (!mark[i] && i != sp)
			fa[find(edge[i][0])] = find(edge[i][1]);
	if (find(S) == find(T))
		return PIVI(INT_MAX, vector<int>());
	PIVI ret(edge[sp][2], vector<int>(1, sp));
	for (int j, i = 0; i < m; ++i)
		if (mark[j = edgeId[i]]){
			fa[find(edge[j][0])] = find(edge[j][1]);
			if (find(S) == find(T)){
				ret.st += edge[j][2];
				ret.nd.push_back(j);
				break;
			}
		}
	return ret;
}

int main(){
	scanf("%d%d", &n, &m);
	scanf("%d%d", &S, &T);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d%d", &u, &v, &edge[i][2]);
		edge[i][0] = u, edge[i][1] = v;
		edgeId[i] = i;
		E[u].push_back(PII(v, i));
		E[v].push_back(PII(u, i));
	}
	sort(edgeId, edgeId + m, [&](const int &l, const int &r)->bool{return edge[l][2] > edge[r][2];});

	DFS1(S);
	if (testLst.size() == 0)
		puts("0\n0\n");
	else{
		PIVI ans;
		ans.st = INT_MAX;
		for (int i = 0; i < testLst.size(); ++i)
			ans = min(ans, solve(testLst[i]));

		if (ans.st == INT_MAX)
			puts("-1");
		else{
			printf("%d\n%d\n", ans.st, ans.nd.size());
			sort(ans.nd.begin(), ans.nd.end());
			for (int i = 0; i < ans.nd.size(); ++i)
				printf("%d%c", ans.nd[i] + 1, "\n "[i + 1 < ans.nd.size()]);
		}
	}
	return 0;
}