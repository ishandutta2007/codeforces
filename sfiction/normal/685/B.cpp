#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 3E5 + 10;

int n, q;
int fa[MAXN], size[MAXN], ms[MAXN];
int ctd[MAXN];
vector<int> E[MAXN];

void DFS(int u){
	size[u] = 1;
	ms[u] = 0;
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != fa[u]){
			DFS(v);
			size[u] += size[v];
			if (size[ms[u]] < size[v])
				ms[u] = v;
		}
	ctd[u] = ms[u] ? ctd[ms[u]] : u;
	int su = max(size[u] - size[ctd[u]], size[ms[ctd[u]]]);
	while (ctd[u] != u){
		int v = fa[ctd[u]];
		int sv = max(size[u] - size[v], size[ms[v]]);
		if (su > sv)
			ctd[u] = v, su = sv;
		else
			break;
	}
}

int main(){
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; ++i){
		scanf("%d", &fa[i]);
		E[i].push_back(fa[i]);
		E[fa[i]].push_back(i);
	}
	DFS(1);
	for (int u, i = 0; i < q; ++i){
		scanf("%d", &u);
		printf("%d\n", ctd[u]);
	}
	return 0;
}