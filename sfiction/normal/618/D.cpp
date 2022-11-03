#include <cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 2E5 + 10;
const int INF = 1 << 29;

int n, x, y;
vector<int> E[MAXN];
int deg[MAXN];
int f[MAXN], g[MAXN];

void DFS(int u, int pre){
	int cnt = 0, w = -1;
	// f:all g:root as an end
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre){
			DFS(v, u);
			cnt += f[v];
			if (w == -1 || g[w] - f[w] > g[v] - f[v])
				w = v;
		}

	f[u] = g[u] = cnt + 1;
	for (int v, i = 0; i < E[u].size(); ++i)
		if ((v = E[u][i]) != pre){
			if (v != w){
				f[u] = min(f[u], cnt - f[v] - f[w] + g[v] + g[w] - 1);
			}
			g[u] = min(g[u], cnt - f[v] + g[v]);
		}
	f[u] = min(f[u], g[u]);
}

int main(){
	scanf("%d%d%d", &n, &x, &y);
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
		++deg[u], ++deg[v];
	}
	if (x >= y){
		bool flag = false;
		for (int i = 1; i <= n; ++i)
			flag |= deg[i] == n - 1;
		printf("%I64d\n", (n - 2) * (ll)(y) + (flag ? x : y));
	}
	else{
		DFS(1, 0);
		printf("%I64d\n", (f[1] - 1) * (ll)y + (n - f[1]) * (ll)(x));
	}
	return 0;
}