//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e5+5, inf = 0x3f3f3f3f; 

int n, m, q, fa[N], vis[N][2], dis[N][2];
pair<int, int> data[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Edge {
	int v, nxt;
	Edge(int a=0, int b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
int h[N], ne = 1;
void add(int u, int v) {
	e[++ne] = Edge(v, h[u]); h[u] = ne;
	e[++ne] = Edge(u, h[v]); h[v] = ne;
}
queue<int> Q;
int bfs(int s, int k) {
	Q.push(s); dis[s][k] = 0; vis[s][k] = 1;
	dis[0][k] = 0;
	int ans = 0;
	while(!Q.empty()) {
		int u = Q.front(); Q.pop();
		if(dis[u][k] > dis[ans][k]) ans = u;
		for(int i=h[u];i;i=e[i].nxt) {
			int v = e[i].v;
			if(!vis[v][k]) {
				vis[v][k] = 1;
				dis[v][k] = dis[u][k] + 1;
				Q.push(v);
			}
		}
	}
	return ans;
}
pair<int, int> split(int x) {
	if(x & 1) return make_pair(x/2+1, x/2);
	return make_pair(x/2, x/2);
}
void init(int x) {rep(i, 1, x) fa[i] = i;}
int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
void merge(int x, int y, int k) {
	int u = find(x), v = find(y);
	if(u != v) {
		if(k) {
			int qwq = 0;
			chkmax(qwq, data[u].first+data[v].first+1);
			chkmax(qwq, data[u].first+data[u].second);
			chkmax(qwq, data[v].first+data[v].second);
			data[u] = split(qwq);
		}
		fa[v] = u;
	}
}

int main() {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis)); 
	scanf("%d%d%d", &n, &m, &q);
	init(n);
	rep(i, 1, m) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		merge(u, v, 0);
	}
	rep(i, 1, n) {
		if(i == fa[i]) {
			int u = bfs(i, 0);
			int v = bfs(u, 1);
			int d = dis[v][1];
			data[i] = split(d);
		}
	}
	rep(i, 1, q) {
		int op, x, y;
		scanf("%d%d", &op, &x);
		if(op == 1) {
			int rt = find(x);
			printf("%d\n", data[rt].first+data[rt].second);
		}
		else {
			scanf("%d", &y);
			merge(x, y, 1);
		}
	}
	return 0;
}