#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>

#define st first
#define nd second

using namespace std;

typedef pair<int, int> PII;

const int MAXN = 25E2 + 10;

int a[MAXN][MAXN], b[MAXN][MAXN];
vector<pair<int, PII> > e;
vector<PII> E[MAXN];

int fa[MAXN];

int find(int x){
	return fa[x] < 0 ? x : (fa[x] = find(fa[x]));
}

void DFS(int a[], int u, int pre, int val){
	a[u] = val;
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i].st) != pre){
			DFS(a, v, u, max(val, E[u][i].nd));
		}
}

int main(){
	int n;
	scanf("%d", &n);
	bool flag = true;
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			scanf("%d", &a[i][j]);
			e.push_back(make_pair(a[i][j], PII(i, j)));
		}
		flag &= a[i][i] == 0;
		for (int j = 1; j < i; ++j)
			flag &= a[i][j] == a[j][i];
	}
	if (!flag){
		puts("NOT MAGIC");
		return 0;
	}

	sort(e.begin(), e.end());

	for (int i = 1; i <= n; ++i)
		fa[i] = -1;
	for (int i = 0; i < e.size(); ++i){
		int u = find(e[i].nd.st), v = find(e[i].nd.nd);
		if (u != v){
			fa[u] += fa[v];
			fa[v] = u;
			E[e[i].nd.st].push_back(PII(e[i].nd.nd, e[i].st));
			E[e[i].nd.nd].push_back(PII(e[i].nd.st, e[i].st));
		}
	}

	for (int i = 1; i <= n; ++i){
		DFS(b[i], i, 0, 0);
		for (int j = 1; j <= n; ++j)
			flag &= a[i][j] == b[i][j];
	}
	puts(flag ? "MAGIC" : "NOT MAGIC");
	return 0;
}