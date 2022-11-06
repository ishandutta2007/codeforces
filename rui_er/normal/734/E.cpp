//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, a[N], dis[N][2], fa[N], col[N], tot;
vector<int> E[N], e[N];
queue<int> q;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
void init(int x) {rep(i, 1, x) fa[i] = i;}
int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}
bool merge(int u, int v) {
	int x = find(u), y = find(v);
	if(x == y) return 0;
	fa[x] = y;
	return 1;
}
int bfs(int s, int c) {
	memset(dis, 0x3f, sizeof(dis));
	q.push(s);
	dis[s][c] = 0;
	int ans = 0;
	while(!q.empty()) {
		int u = q.front(); q.pop();
		ans = u;
		for(auto v : e[u]) {
			if(dis[v][c] > dis[u][c] + 1) {
				dis[v][c] = dis[u][c] + 1;
				q.push(v);
			}
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	init(n);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
		if(a[u] == a[v]) merge(u, v);
	}
	rep(i, 1, n) if(i == find(i)) col[i] = ++tot;
	rep(i, 1, n) if(i != find(i)) col[i] = col[find(i)];
	rep(u, 1, n) {
		for(auto v : E[u]) {
			if(col[u] != col[v]) {
				e[col[u]].push_back(col[v]);
				e[col[v]].push_back(col[u]);
			}
		}
	}
	int x = bfs(1, 0);
	int y = bfs(x, 1);
	int d = dis[y][1];
	printf("%d\n", (d+1)/2);
    return 0;
}