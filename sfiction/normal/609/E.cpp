#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2E5 + 10, MAXM = 2E5 + 10, MAXK = 18;

int n, m;
vector<PII> E[MAXN];
pair<PII, PII> e[MAXM];

int fa[MAXN];

int dep[MAXN];
int p[MAXK][MAXN], val[MAXK][MAXN];

ll ans[MAXM];

int find(int x){
	return fa[x] < 0 ? x : (fa[x] = find(fa[x]));
}

bool merge(int u, int v){
	u = find(u), v = find(v);
	if (u != v){
		fa[u] += fa[v];
		fa[v] = u;
		return true;
	}
	return false;
}

void DFS(int u){
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i].st) != p[0][u]){
			dep[v] = dep[u] + 1;
			p[0][v] = u;
			val[0][v] = E[u][i].nd;
			DFS(v);
		}
}

void LCA_build(){
	for (int i = 1; i < MAXK; ++i)
		for (int j = 1; j <= n; ++j){
			p[i][j] = p[i - 1][p[i - 1][j]];
			val[i][j] = max(val[i - 1][j], val[i - 1][p[i - 1][j]]);
		}
}

PII LCA_get(int u, int v){
	if (dep[u] < dep[v])
		swap(u, v);

	int ret = 0;
	for (int i = MAXK - 1; i >= 0; --i)
		if (dep[p[i][u]] >= dep[v]){
			ret = max(ret, val[i][u]);
			u = p[i][u];
		}
	if (u == v)
		return PII(u, ret);

	for (int i = MAXK - 1; i >= 0; --i)
		if (p[i][u] != p[i][v]){
			ret = max(ret, val[i][u]);
			ret = max(ret, val[i][v]);
			u = p[i][u];
			v = p[i][v];
		}
	ret = max(ret, val[0][u]);
	ret = max(ret, val[0][v]);
	return PII(p[0][u], ret);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d%d", &e[i].nd.st, &e[i].nd.nd, &e[i].st.st);
		e[i].st.nd = i;
	}
	sort(e, e + m);

	for (int i = 1; i <= n; ++i)
		fa[i] = -1;
	ll sum = 0;
	for (int u, v, i = 0; i < m; ++i)
		if (merge(u = e[i].nd.st, v = e[i].nd.nd)){
			sum += e[i].st.st;
			ans[e[i].st.nd] = 1;
			E[u].push_back(PII(v, e[i].st.st));
			E[v].push_back(PII(u, e[i].st.st));
		}

	dep[1] = 1;
	DFS(1);
	LCA_build();

	for (int i = 0; i < m; ++i)
		if (ans[e[i].st.nd])
			ans[e[i].st.nd] = sum;
		else
			ans[e[i].st.nd] = sum - LCA_get(e[i].nd.st, e[i].nd.nd).nd + e[i].st.st;
	for (int i = 0; i < m; ++i)
		printf("%I64d\n", ans[i]);

	return 0;
}