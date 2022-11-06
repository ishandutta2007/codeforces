//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, dis[N], col[N], x, y, d[N][2], mx;
vector<int> e[N];
queue<int> q;
vector<tuple<int, int, int> > ans;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
int bfs(int s) {
//	debug;
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	q.push(s);
	int ans = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		ans = u;
		for(auto v : e[u]) {
			if(dis[v] > dis[u] + 1) {
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	return ans;
}
int dfs1(int u, int f, int t) {
//	debug;
	if(u == t) {
		col[u] = 1;
		return 1;
	}
	for(auto v : e[u]) {
		if(v != f) {
			if(dfs1(v, u, t)) {
				col[u] = 1;
				return 1;
			}
		}
	}
	return 0;
}
void dfs2(int u, int f, int c) {
//	debug;
	d[u][c] = d[f][c] + 1;
	for(auto v : e[u]) {
		if(v != f) {
			dfs2(v, u, c);
		}
	}
}
void dfs3(int u, int f) {
//	debug;
	for(auto v : e[u]) {
		if(v != f) {
			dfs3(v, u);
		}
	}
	if(!col[u]) {
		if(d[u][0] > d[u][1]) {
			ans.push_back(make_tuple(u, x, u));
			mx += d[u][0];
		}
		else {
			ans.push_back(make_tuple(u, y, u));
			mx += d[u][1];
		}
	}
}
void jump(int s, int t) {
//	debug;
	int u = s;
	while(u != t) {
//		printf("%d (%d -> %d)\n", u, s, t);
//		system("pause > nul");
		ans.push_back(make_tuple(u, t, u));
		mx += d[u][1];
		for(auto v : e[u]) {
			if(col[v]) {
				col[u] = 0;
				u = v;
			}
		}
	}
}

signed main() {
	d[0][0] = d[0][1] = -1;
	scanf("%lld", &n);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%lld%lld", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	x = bfs(1);
	y = bfs(x);
	dfs1(x, 0, y);
	dfs2(x, 0, 0);
	dfs2(y, 0, 1);
	dfs3(x, 0);
	jump(x, y);
	printf("%lld\n", mx);
	for(auto i : ans) {
		int u = get<0>(i);
		int v = get<1>(i);
		int w = get<2>(i);
		printf("%lld %lld %lld\n", u, v, w);
	}
    return 0;
}