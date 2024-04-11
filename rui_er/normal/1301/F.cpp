//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 1e3+5, inf = 0x3f3f3f3f;
const int nxt[4][2] = {
	{0, 1}, 
	{0, -1}, 
	{1, 0}, 
	{-1, 0}
};

int n, m, k, T, a[N][N], vis[45], dis[45][N][N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
vector<tuple<int, int> > e[45];
queue<tuple<int, int> > q;
void bfs(int col) {
	rep(i, 1, n) rep(j, 1, m) dis[col][i][j] = inf;
	rep(i, 1, k) vis[i] = 0;
	vis[col] = 1;
	for(auto i : e[col]) {
		int x = get<0>(i);
		int y = get<1>(i);
		q.push(make_tuple(x, y));
		dis[col][x][y] = 0;
	}
	while(!q.empty()) {
		tuple<int, int> u = q.front(); q.pop();
		int x = get<0>(u);
		int y = get<1>(u);
		rep(i, 0, 3) {
			int dx = x + nxt[i][0];
			int dy = y + nxt[i][1];
			if(dis[col][dx][dy] > dis[col][x][y] + 1) {
				dis[col][dx][dy] = dis[col][x][y] + 1;
				q.push(make_tuple(dx, dy));
			}
		}
		if(vis[a[x][y]]) continue;
		vis[a[x][y]] = 1;
		for(auto i : e[a[x][y]]) {
			int dx = get<0>(i);
			int dy = get<1>(i);
			if(dis[col][dx][dy] > dis[col][x][y] + 1) {
				dis[col][dx][dy] = dis[col][x][y] + 1;
				q.push(make_tuple(dx, dy));
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	rep(i, 1, n) rep(j, 1, m) {
		scanf("%d", &a[i][j]);
		e[a[i][j]].push_back(make_pair(i, j));
	}
	rep(i, 1, k) bfs(i);
	for(scanf("%d", &T);T;T--) {
		int X1, Y1, X2, Y2;
		scanf("%d%d%d%d", &X1, &Y1, &X2, &Y2);
		int ans = abs(X1 - X2) + abs(Y1 - Y2);
		rep(i, 1, k) chkmin(ans, dis[i][X1][Y1]+dis[i][X2][Y2]+1);
		printf("%d\n", ans);
	}
	return 0;
}