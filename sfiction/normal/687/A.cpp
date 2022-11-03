#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10;

int n, m;
int fa[MAXN];
bool dis[MAXN];

int find(int x){
	if (x == fa[x])
		return x;
	find(fa[x]);
	dis[x] ^= dis[fa[x]];
	return fa[x] = fa[fa[x]];
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		fa[i] = i, dis[i] = 0;
	bool ans = true;
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		int ru = find(u), rv = find(v);
		if (ru != rv){
			fa[rv] = ru;
			dis[rv] = dis[u] ^ dis[v] ^ 1;
		}
		else
			ans &= dis[u] ^ dis[v];
	}
	if (ans){
		vector<int> a[2];
		for (int i = 1; i <= n; ++i){
			find(i);
			a[dis[i]].push_back(i);
		}
		for (int i = 0; i < 2; ++i){
			printf("%d\n", (int)a[i].size());
			for (int j = 0; j < a[i].size(); ++j)
				printf("%d%c", a[i][j], "\n "[j + 1 < a[i].size()]);
		}
	}
	else
		puts("-1");
	return 0;
}