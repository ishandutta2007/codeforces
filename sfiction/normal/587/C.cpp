#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10, MAXP = 17, MAXA = 10;
const int INF = 0x7f7f7f7f;

int n, m, q;
int cnt[MAXN];
vector<int> E[MAXN];

int p[MAXN][MAXP], dep[MAXN];
int val[MAXN][MAXP][MAXA + 1];

void LCADFS(int u){
	for (int i = 0; i < E[u].size(); ++i)
		if (E[u][i] != p[u][0]){
			p[E[u][i]][0] = u;
			dep[E[u][i]] = dep[u] + 1;
			LCADFS(E[u][i]);
		}
}

void merge(int a[], int b[], int c[]){
	for (int i = 0, j = 0, k = 0; k < MAXA; ++k)
		c[k] = i < MAXA && (j == MAXA || a[i] < b[j]) ? a[i++] : b[j++];
}

int LCABuild(){
	p[0][0] = p[1][0] = 0;
	dep[0] = 0, dep[1] = 1;
 	LCADFS(1);
	
	for (int i = 0; i < MAXP - 1; ++i)
		for (int j = 1; j <= n; ++j){
			p[j][i + 1] = p[p[j][i]][i];
			if (p[j][i + 1])
				merge(val[j][i], val[p[j][i]][i], val[j][i + 1]);
		}
}

int getLCA(int u, int v, int c[]){
	if (dep[u] < dep[v])
		swap(u, v);

	int t[MAXA];
	for (int i = MAXP - 1; i >= 0; --i)
		if (dep[p[u][i]] >= dep[v]){
			memcpy(t, c, sizeof(t));
			merge(val[u][i], t, c);
			u = p[u][i];
		}

	for (int i = MAXP - 1; i >= 0; --i)
		if (p[u][i] != p[v][i]){
			memcpy(t, c, sizeof(t));
			merge(val[u][i], t, c);
			u = p[u][i];
			memcpy(t, c, sizeof(t));
			merge(val[v][i], t, c);
			v = p[v][i];
		}

	memcpy(t, c, sizeof(t));
	merge(val[u][0], t, c);
	if (u != v){
		memcpy(t, c, sizeof(t));
		merge(val[v][0], t, c);
		memcpy(t, c, sizeof(t));
		merge(val[p[u][0]][0], t, c);
	}
	return p[u][0];
}

int main(){
	scanf("%d%d%d", &n, &m, &q);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i)
		memset(val[i][0], 0x7f, sizeof(val[0][0]));

	for (int u, i = 1; i <= m; ++i){
		scanf("%d", &u);
		int j = MAXA - 1;;
		for (; j >= 0 && val[u][0][j] > i; --j)
			val[u][0][j + 1] = val[u][0][j];
		val[u][0][j + 1] = i;
	}
	LCABuild();

	int ans[MAXA];
	for (int u, v, a, i = 0; i < q; ++i){
		scanf("%d%d%d", &u, &v, &a);
		memset(ans, 0x7f, sizeof(ans));
		getLCA(u, v, ans);

		int len = 0;
		for (; len < a && ans[len] < INF; ++len);
		printf("%d", len);
		for (int j = 0; j < len; ++j)
			printf(" %d", ans[j]);
		puts("");
	}
	return 0;
}