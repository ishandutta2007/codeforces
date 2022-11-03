#include <cstdio>
#include <queue>

using namespace std;

const int MAXN = 4E2 + 10;

int E[MAXN][MAXN];
int dis[MAXN];

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		E[u][v] = E[v][u] = true;
	}
	int type = !E[1][n];
	queue<int> Q;
	dis[1] = 1;
	Q.push(1);
	while (!Q.empty() && !dis[n]){
		int u = Q.front();
		Q.pop();
		for (int i = 1; i <= n; ++i)
			if (E[u][i] == type && !dis[i]){
				dis[i] = dis[u] + 1;
				Q.push(i);
			}
	}
	printf("%d\n", dis[n] - 1);
	return 0;
}