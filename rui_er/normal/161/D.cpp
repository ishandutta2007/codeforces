//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 5e4+5;

int n, k, rt, rtsz, sz[N], vis[N], dis[N], d[N], tot;
struct Edge {
	int v, w, nxt;
	Edge(int a=0, int b=0, int c=0) : v(a), w(b), nxt(c) {}
	~Edge() {}
}e[N<<1];
int h[N], ne = 1;
void add(int u, int v, int w) {
	e[++ne] = Edge(v, w, h[u]); h[u] = ne;
	e[++ne] = Edge(u, w, h[v]); h[v] = ne;
}
void dfs_findroot(int u, int fa, int SZ) {
	sz[u] = 1;
	int maxpt = 0;
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v, w = e[i].w;
		if(v != fa && !vis[v]) {
			dfs_findroot(v, u, SZ);
			sz[u] += sz[v];
			maxpt = max(maxpt, sz[v]);
		}
	}
	maxpt = max(maxpt, SZ-sz[u]);
	if(maxpt < rtsz) {
		rtsz = maxpt;
		rt = u;
	}
}
void dfs_dis(int u, int fa) {
	d[++tot] = dis[u];
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v, w = e[i].w;
		if(v != fa && !vis[v]) {
			dis[v] = dis[u] + w;
			dfs_dis(v, u);
		}
	}
}
int calc(int u, int k) {
	tot = 0; dfs_dis(u, 0);
	sort(d+1, d+1+tot);
	int L = 1, R = tot, ans = 0;
	while(L < R) {
		while(L < R && d[L] + d[R] > k) --R;
		ans += R - L; ++L;
	}
	return ans;
}
int divid(int u, int fa, int SZ) {
	rtsz = SZ; dfs_findroot(u, 0, SZ);
	u = rt; vis[u] = 1; dis[u] = 0;
	int ans = calc(u, k) - calc(u, k-1);
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v, w = e[i].w;
		if(v != fa && !vis[v]) {
			dis[v] = w;
			ans -= calc(v, k) - calc(v, k-1);
			ans += divid(v, u, tot);
		}
	}
	return ans;
}

int main() {
	scanf("%d%d", &n, &k);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v, 1);
	}
	printf("%d\n", divid(1, 0, n));
    return 0;
}