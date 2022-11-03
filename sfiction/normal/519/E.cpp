/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 519E
 */
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 100, MAXD = 17;

int n;
vector<int> E[MAXN];

int size[MAXN];
int depth[MAXN];
int par[MAXN][MAXD];

void lcaDFS(int pre, int u){
	size[u] = 1;	//only for this problem
	depth[u] = depth[pre] + 1;
	par[u][0] = pre;
	for (int i=E[u].size()-1;i>=0;--i)
		if (E[u][i] != pre){
			lcaDFS(u, E[u][i]);
			size[u] += size[E[u][i]];
		}
}

int lcaPre(){
	depth[0] = 0;
	lcaDFS(0, 1);

	for (int j=1;j<MAXD;++j)
		for (int i=0;i<=n;++i)
			par[i][j] = par[par[i][j - 1]][j - 1];
}

int lcaPar(int u, int diff){
	for (int i=0;diff;++i,diff>>=1)
		if (diff & 1)
			u = par[u][i];
	return u;
}

int getLCA(int u, int v){
	if (depth[u] < depth[v])
		swap(u, v);
	u = lcaPar(u, depth[u] - depth[v]);
	if (u == v)
		return u;

	for (int i=MAXD-1;i>=0;--i)
		if (par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	return par[u][0];
}

int main(){
	scanf("%d", &n);
	for (int u,v,i=1;i<n;++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	lcaPre();

	int m;
	scanf("%d", &m);
	for (int u,v;m;--m){
		scanf("%d%d", &u, &v);
		if (u == v){
			printf("%d\n", n);
			continue;
		}
		if (depth[u] < depth[v])
			swap(u, v);
		if ((depth[u] - depth[v]) & 1){
			puts("0");
			continue;
		}

		int lca = getLCA(u, v);
		int mid = lcaPar(u, (depth[u] + depth[v]) / 2 - depth[lca]);
		if (mid == lca)
			printf("%d\n", n - size[lcaPar(u, depth[u] - depth[mid] - 1)] - size[lcaPar(v, depth[v] - depth[mid] - 1)]);
		else
			printf("%d\n", size[mid] - size[lcaPar(u, depth[u] - depth[mid] - 1)]);
	}
	return 0;
}