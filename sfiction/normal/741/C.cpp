#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1E5 + 10;

int n;
vector<int> E[MAXN << 1];
int e[MAXN][2];
int color[MAXN << 1];

void DFS(int u, int c){
	color[u] = c;
	for (int i = 0; i < E[u].size(); ++i)
		if (!color[E[u][i]])
			DFS(E[u][i], 3 ^ c);
}

int main(){
	scanf("%d", &n);
	for (int u, v, i = 0; i < n; ++i){
		scanf("%d%d", &u, &v);
		e[i][0] = u, e[i][1] = v;
		E[u].push_back(v);
		E[v].push_back(u);
		E[i << 1 | 1].push_back(i + 1 << 1);
		E[i + 1 << 1].push_back(i << 1 | 1);
	}
	for (int i = n << 1; i > 0; --i)
		if (!color[i])
			DFS(i, 1);
	for (int i = 0; i < n; ++i)
		printf("%d %d\n", color[e[i][0]], color[e[i][1]]);
	return 0;
}