#include <cstdio>

const int MAXN = 1E5 + 10;

int fa[MAXN], sz[MAXN];

int find(int x){
	return fa[x] < 0 ? x : (fa[x] = find(fa[x]));
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		fa[i] = -1;
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		u = find(u), v = find(v);
		if (u == v)
			++sz[u];
		else{
			fa[u] += fa[v];
			fa[v] = u;
			sz[u] += sz[v] + 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
		cnt += fa[i] + sz[i] == -1;
	printf("%d\n", cnt);
	return 0;
}