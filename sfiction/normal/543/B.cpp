#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 3E3 + 10;
const int INF = 0x01010101;

int dis[MAXN][MAXN];
vector<int> E[MAXN];

void SPFA(int start, int (&dis)[MAXN]){
	static const int MAXNN = (1 << 12) - 1;
	static int que[MAXNN];
	static bool in[MAXN];
	int l = 0, r = 1;
	memset(dis, 1, sizeof(dis));
	memset(in, 0, sizeof(in));
	dis[start] = 0;
	que[0] = start;
	in[start] = true;
	for (int u, v; l != r; l = l + 1 & MAXNN){
		u = que[l];
		in[u] = false;
		for (int i = E[u].size() - 1; i >= 0; --i)
			if (dis[v = E[u][i]] > dis[u] + 1){
				dis[v] = dis[u] + 1;
				if (!in[v]){
					que[r] = v;
					in[v] = true;
					r = r + 1 & MAXNN;
				}
			}
	}
}

int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for (int u, v, i = 0; i < m; ++i){
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i)
		SPFA(i, dis[i]);

	int s1, t1, l1;
	int s2, t2, l2;
	scanf("%d%d%d%d%d%d", &s1, &t1, &l1, &s2, &t2, &l2);
	int ans = dis[s1][t1] <= l1 && dis[s2][t2] <= l2 ? dis[s1][t1] + dis[s2][t2] : INF;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j){
			int m = dis[i][j], m1, m2;
			m1 = dis[s1][i] + m + dis[j][t1];
			m2 = dis[s2][i] + m + dis[j][t2];
			ans = min(ans, m1 <= l1 && m2 <= l2 ? m1 + m2 - m : INF);
			m1 = dis[s1][i] + m + dis[j][t1];
			m2 = dis[s2][j] + m + dis[i][t2];
			ans = min(ans, m1 <= l1 && m2 <= l2 ? m1 + m2 - m : INF);
		}
	printf("%d\n", ans < INF ? m - ans : -1);
	return 0;
}