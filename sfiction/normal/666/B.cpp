#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 3E3 + 10;

int n, m;
vector<int> E[MAXN], F[MAXN], pre[MAXN], nex[MAXN];
int dis[MAXN][MAXN];

void BFS(vector<int> E[], int st, int dis[], vector<int> &f){
	static int que[MAXN];
	int l = 0, r = 1;
	for (int i = 1; i <= n; ++i)
		dis[i] = -1;
	dis[st] = 0;
	que[0] = st;
	for (; l < r; ++l){
		int u = que[l];
		for (int v, i = 0; i < E[u].size(); ++i)
			if (!~dis[v = E[u][i]]){
				dis[v] = dis[u] + 1;
				que[r++] = v;
			}
	}
	for (int i = r - 1; i > 0 && i >= r - 4; --i)
		f.push_back(que[i]);
}

int main(){
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		F[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i){
		BFS(E, i, dis[i], nex[i]);
		BFS(F, i, dis[0], pre[i]);
	}

	int ans = 0;
	int out[4];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			if (dis[i][j] <= 0)
				continue;

			for (int k = 0; k < pre[i].size(); ++k)
				for (int l = 0; l < nex[j].size(); ++l)
					if (pre[i][k] != j && nex[j][l] != i && pre[i][k] != nex[j][l]){
						int len = dis[pre[i][k]][i] + dis[i][j] + dis[j][nex[j][l]];
						if (ans < len){
							ans = len;
							out[0] = pre[i][k];
							out[1] = i;
							out[2] = j;
							out[3] = nex[j][l];
						}
					}
		}
	printf("%d %d %d %d\n", out[0], out[1], out[2], out[3]);
	return 0;
}