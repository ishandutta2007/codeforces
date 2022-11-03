/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 208E
 */
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 100, MAXD = 17;

int n;
vector<int> E[MAXN];

int depth[MAXN];
int par[MAXN][MAXD];

int dfnCnt, dfn[MAXN][2];

vector<int> layer[MAXN];

void DFS(int pre, int u){
	dfn[u][0] = ++dfnCnt;
	depth[u] = depth[pre] + 1;
	par[u][0] = pre;
	layer[depth[u]].push_back(dfnCnt);

	for (int i=E[u].size()-1;i>=0;--i)
		DFS(u, E[u][i]);

	dfn[u][1] = ++dfnCnt;
	layer[depth[u]].push_back(dfnCnt);
}

void lcaPre(){
	dfnCnt = 0;
	depth[0] = 0;
	for (int i=E[0].size()-1;i>=0;--i)
		DFS(0, E[0][i]);

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

//return number of elements which smaller than k
int smaller(vector<int> &a, int k){
	int high = a.size(), low = 0;
	int mid;
	while (high > low + 1){
		mid = (high + low) >> 1;
		if (a[mid] < k)
			low = mid;
		else
			high = mid;
	}
	return low + (a[low] < k);
}

int main(){
	scanf("%d", &n);
	for (int t,i=1;i<=n;++i){
		scanf("%d", &t);
		E[t].push_back(i);
	}
	lcaPre();

	int m;
	scanf("%d", &m);
	for (int v,p;m--;){
		scanf("%d%d", &v, &p);
		v = lcaPar(v, p);
		if (!v)
			putchar('0');
		else
			printf("%d", ((smaller(layer[depth[v] + p], dfn[v][1]) - smaller(layer[depth[v] + p], dfn[v][0])) >> 1) - 1);

		if (m)
			putchar(' ');
	}
	return 0;
}