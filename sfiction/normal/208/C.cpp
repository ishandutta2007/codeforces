/*
 * ID: Sfiction
 * OJ: CF
 * PROB: 208C
 */
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100 + 10;

int n, m;
vector<int> E[MAXN];
bool vis[MAXN];
int dis[2][MAXN];
double cnt[2][MAXN];

void BFS(int start, int dis[], double cnt[]){
	queue<int> Q;

	memset(vis, 0, sizeof(vis));
	vis[start] = true;
	dis[start] = 0;
	cnt[start] = 1;
	Q.push(start);
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		for (int v,i=E[u].size()-1;i>=0;--i)
			if (!vis[v = E[u][i]]){
				vis[v] = true;
				dis[v] = dis[u] + 1;
				cnt[v] += cnt[u];
				Q.push(v);
			}
			else if (dis[u] + 1 == dis[v])
				cnt[v] += cnt[u];
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for (int u,v,i=0;i<m;++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}

	memset(cnt, 0, sizeof(cnt));
	BFS(1, dis[0], cnt[0]);
	BFS(n, dis[1], cnt[1]);

	int len = dis[0][n];
	double ans = cnt[0][n];
	for (int i=2;i<n;++i){
		if (dis[0][i] + dis[1][i] == len)
			ans = max(ans, cnt[0][i] * cnt[1][i] * 2);
//		printf("%d %d %d %d %d\n", i, dis[0][i], dis[1][i], cnt[0][i], cnt[1][i]);
	}
	printf("%.12lf", ans / cnt[0][n]);

	return 0;
}