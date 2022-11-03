#include <cstdio>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 2E5 + 10, MAXK = 18;
const ll INF = 1ll << 61;

int n;
vector<PII> E[MAXN];
int depth[MAXN];
ll val[MAXN];
int id[MAXN];

int p[MAXN][MAXK];
int fa[MAXN];

int LCA_DFS(int u, int pre){
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i].st) != pre){
			depth[v] = depth[u] + 1;
			fa[v] = p[v][0] = u;
			id[v] = E[u][i].nd;
			LCA_DFS(v, u);
		}
}

void LCA_build(){
	for (int j = 1; j < MAXK; ++j)
		for (int i = 1; i <= n; ++i)
			p[i][j] = p[p[i][j - 1]][j - 1];
}

int LCA_query(int u, int v){
	if (depth[u] < depth[v])
		swap(u, v);
	for (int i = MAXK - 1; depth[u] > depth[v] && i >= 0; --i)
		if (depth[p[u][i]] >= depth[v])
			u = p[u][i];
	if (u == v)
		return u;
	for (int i = MAXK - 1; i >= 0; --i)
		if (p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i];
	return p[u][0];
}

void find(int u, int limit, ll &res){
	if (depth[u] <= limit)
		return;

	if (val[id[fa[u]]] == 1)
		fa[u] = fa[fa[u]];
	res /= val[id[u]];
	if (res)
		find(fa[u], limit, res);
}

int main(){
	int q;
	scanf("%d%d", &n, &q);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d%I64d", &u, &v, &val[i]);
		E[u].push_back(PII(v, i));
		E[v].push_back(PII(u, i));
	}
	depth[0] = -1;
	depth[1] = 0;
	fa[1] = p[1][0] = 0;
	LCA_DFS(1, 0);
	LCA_build();

	int com;
	ll a, b, c;
	for (int i = 0; i < q; ++i){
		scanf("%d%I64d%I64d", &com, &a, &b);
		if (com == 1){
			scanf("%I64d", &c);
			int top = depth[LCA_query(a, b)];
			find(a, top, c);
			find(b, top, c);
			printf("%I64d\n", c);
		}
		else
			val[a] = b;
	}
	return 0;
}