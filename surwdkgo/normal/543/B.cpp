#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif
#define MAXN 3010
int n, m;
int dis[MAXN][MAXN];
int vis[MAXN];
vector<int> edg[MAXN];
int g[4];
int gt[2];
int q[3010], pus, pop;
int ans;

void lemon() {  
	scanf("%d%d", &n, &m);
	rep(i,1,m) {
		int u,v;
		scanf("%d%d", &u, &v);
		edg[u].push_back(v);
		edg[v].push_back(u);
	}
	scanf("%d%d%d%d%d%d", &g[0], &g[1], &gt[0], &g[2], &g[3], &gt[1]);
	rep(i,1,n) {
		memset(vis, 0, sizeof(vis));
		dis[i][i] = 0;
		vis[i] = 1;
		pus = 1;
		pop=  0;
		q[0] = i;
		while (pop < pus) {
			int v = q[pop++];
			rep(j,0,SIZE(edg[v])-1) {
				if (!vis[edg[v][j]]) {
					vis[edg[v][j]] = 1;
					dis[i][edg[v][j]] = dis[i][v] + 1;
					q[pus++] = edg[v][j];
				}
			}
		}
	}
	ans = dis[g[0]][g[1]] + dis[g[2]][g[3]];
	if (dis[g[0]][g[1]] > gt[0] || dis[g[2]][g[3]] > gt[1]) {
		puts("-1");
		return;
	}
	rep(i,1,n) {
		rep(j,1,n) {
			if (dis[g[0]][i] + dis[i][j] + dis[j][g[1]] <= gt[0] && dis[g[2]][i] + dis[i][j] + dis[j][g[3]] <= gt[1]) {
				ans = min(ans, dis[g[0]][i] + dis[i][j] + dis[j][g[1]] + dis[g[2]][i] + dis[j][g[3]]);
			}
			if (dis[g[0]][i] + dis[i][j] + dis[j][g[1]] <= gt[0] && dis[g[3]][i] + dis[i][j] + dis[j][g[2]] <= gt[1]) {
				ans = min(ans, dis[g[0]][i] + dis[i][j] + dis[j][g[1]] + dis[g[3]][i] + dis[j][g[2]]);
			}
		}
	}
	printf("%d\n", m - ans);
}
int main() {
  ios::sync_with_stdio(true);
  #ifndef ONLINE_JUDGE
   // freopen("","r",stdin);
  #endif
  lemon();
  return 0;
}