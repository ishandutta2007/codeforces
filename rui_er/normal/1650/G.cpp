// LUOGU_RID: 91991512
// Problem: CF1650G Counting Shortcuts
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1650G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=(y);x<=(z);x++)
#define per(x,y,z) for(int x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 2e5+5, mod = 1e9+7, inf = 0x3f3f3f3f;

int T, n, m, s, t, dis[2][N], vis[2][N], dp[2][N];
vector<int> e[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void bfs(int s, int _) {
	rep(i, 1, n) {
		dis[_][i] = inf;
		vis[_][i] = dp[_][i] = 0;
	}
	queue<int> q;
	dis[_][s] = 0;
	vis[_][s] = dp[_][s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int v : e[u]) {
			if(!vis[_][v]) {
				dis[_][v] = dis[_][u] + 1;
				vis[_][v] = 1;
				dp[_][v] = dp[_][u];
				q.push(v);
			}
			else if(dis[_][v] == dis[_][u] + 1) {
				dp[_][v] = (dp[_][v] + dp[_][u]) % mod;
			}
		}
	}
}

int main() {
	for(scanf("%d", &T); T; T--) {
		scanf("%d%d%d%d", &n, &m, &s, &t);
		rep(i, 1, m) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		bfs(s, 0);
		bfs(t, 1);
		int ans = dp[0][t];
		rep(u, 1, n) {
			for(int v : e[u]) {
				if(dis[0][v] == dis[0][u]) {
					if(dis[0][u] + dis[1][v] == dis[0][t]) {
						ans = (ans + 1LL * dp[0][u] * dp[1][v] % mod) % mod;
					}
				}
			}
		}
		printf("%d\n", ans);
		rep(i, 1, n) e[i].clear();
	}
	return 0;
}