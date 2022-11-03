#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 3E5 + 10, SIGMA = 26;

int n;
int c[MAXN];
char s[MAXN];

vector<int> E[MAXN];
int cnt, a[MAXN][SIGMA];
int size[MAXN];

int ans, ansk;

int merge(int u, int v){
	int i = s[v] - 'a';
	if (a[u][i]){
		int ret = 1;
		for (int j = 0; j < SIGMA; ++j)
			if (a[v][j])
				ret += merge(a[u][i], a[v][j]);
		return ret;
	}
	else{
		a[u][i] = v;
		return 0;
	}
}

void DFS(int u, int pre){
	size[u] = 1;
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre){
			DFS(v, u);
			size[u] += size[v];
			size[u] -= merge(u, v);
		}
	if (ans < size[u] + c[u])
		ans = size[u] + c[u], ansk = 1;
	else
		ansk += ans == size[u] + c[u];
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &c[i]);
	scanf("%s", s + 1);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1, 0);
	printf("%d\n%d\n", ans, ansk);
	return 0;
}