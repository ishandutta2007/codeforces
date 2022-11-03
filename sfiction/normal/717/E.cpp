#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 2E5 + 10;

int n;
int color[MAXN];
vector<int> E[MAXN];
int r, ans[MAXN << 2];

void DFS(int u, int pre){
	if (u > 1)
		color[u] ^= 1;
	ans[r++] = u;
	for (int v, i = 0; i < E[u].size(); ++i){
		if ((v = E[u][i]) == pre)
			continue;
		DFS(v, u);
		color[u] ^= 1;
		ans[r++] = u;

		if (color[v]){
			color[v] ^= 1, color[u] ^= 1;
			ans[r++] = v, ans[r++] = u;
		}
	}
}

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i){
		scanf("%d", &color[i]);
		color[i] = !~color[i];
	}
	for (int u, v, i = 1; i < n; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1, 0);
	if (color[1])
		--r;
	for (int i = 0; i < r; ++i)
		printf("%d%c", ans[i], "\n "[i + 1 < r]);
	return 0;
}