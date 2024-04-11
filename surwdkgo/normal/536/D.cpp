#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long LL;

int n, m, s[2];
int p[2010];
int adj[2010][2010];
LL dp[2][2010][2010];
LL dis[2][2010];
struct D{
	LL v;
	int i;
	bool operator <(const D&b) const {
		return v < b.v;
	}
} sd[2][2010];
int vis[2010];
int jb[2][2010];
int main() {
	scanf("%d%d%d%d", &n, &m, &s[0], &s[1]);
	memset(adj, 63, sizeof(adj));
	s[0]--, s[1]--;
	for (int i=0; i<n; i++) {
		scanf("%d", &p[i]);
		adj[i][i] = 0;
	}
	for (int i=0; i<m; i++) {
		int u, v, t;
		scanf("%d%d%d", &u, &v, &t);
		u--;
		v--;
		adj[v][u] =adj[u][v] = min(adj[u][v], t);
	}
	for (int i=0; i<2; i++) {
		memset(dis[i], 63, sizeof(dis[i]));
		memset(vis, 0, sizeof(vis));;
		dis[i][s[i]] = 0;
		for (int itr = 0; itr < n; itr++) {
			int mp = -1;
			for (int j=0; j<n; j++) {
				if (!vis[j]) {
					if (mp == -1 || dis[i][mp] > dis[i][j]) mp = j;
				}
			}
			vis[mp] = 1;
			for (int j=0; j<n; j++) {
				if (adj[mp][j] <= 1000000000) {
					dis[i][j] = min(dis[i][j], dis[i][mp] + adj[mp][j]);
				}
			}
		}
		for (int j=0; j<n; j++) sd[i][j].v = dis[i][j], sd[i][j].i = j;
		std::sort(sd[i], sd[i]+n);
		for (int j=1; j<n; j++) jb[i][j] = sd[i][j].v == sd[i][j-1].v ? jb[i][j-1] : j;
	}
	//memset(dp, -63, sizeof(dp));
	//for (int j=0; j<n; j++) dp[0][n-1][j] = dp[1][n-1][j] = dp[0][j][n-1] = dp[1][j][n-1] = 0;
	
	for (int j=n-1; j>=0; j--) {
		if (j && jb[0][j] == jb[0][j-1]) continue;
		for (int k=n-1; k>=0; k--) {
			if (k && jb[1][k] == jb[1][k-1]) continue;

			//printf("At %d %d:\n", j, k);

			LL sum=0, cnt=0, nex;
			for (nex=j; nex < n && jb[0][nex] == jb[0][j]; nex++) {
				if (!k || dis[1][sd[0][nex].i] > sd[1][k-1].v) {
					cnt++;
					sum += p[sd[0][nex].i];
				}
			}
			if (cnt) dp[0][j][k] = max(dp[0][nex][k], -dp[1][nex][k]) + sum;
			else  dp[0][j][k] = dp[0][nex][k];
			sum=0, cnt=0, nex;
			for (nex=k; nex < n && jb[1][nex] == jb[1][k]; nex++) {
				if (!j || dis[0][sd[1][nex].i] > sd[0][j-1].v) {
					cnt++;
					sum += p[sd[1][nex].i];
				}
			}
			if (cnt) dp[1][j][k] = max(dp[1][j][nex], -dp[0][j][nex]) + sum;
			else  dp[1][j][k] = dp[1][j][nex];
		}
	}
	printf("%s\n", dp[0][0][0] > 0 ? "Break a heart" : dp[0][0][0] < 0 ? "Cry" : "Flowers");
	return 0;
}