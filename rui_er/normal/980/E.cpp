//By: Luogu@rui_er(122461)..
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;

int n, k;
int dfn[N], fa[N], depth[N], sz[N], ok[N], tot, cnt;
struct Edge {
	int v, nxt;
	Edge(int a=0, int b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
int h[N], ne;
void add(int u, int v) {
	e[++ne] = Edge(v, h[u]); h[u] = ne;
	e[++ne] = Edge(u, h[v]); h[v] = ne; 
}

int BIT[N];
int lowbit(int x) {return x&(-x);}
void upd(int x, int k) {for(;x<=n;x+=lowbit(x)) BIT[x] += k;}
int ask(int x) {int res = 0; for(;x;x-=lowbit(x)) res += BIT[x]; return res;}

void dfs(int u, int f) {
	dfn[u] = ++tot;
	fa[u] = f; sz[u] = 1;
	depth[u] = depth[f] + 1;
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(v != f) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
}
void calc(int x) {
	if(depth[x] - ask(dfn[x]) > n - k - cnt) return;
	for(;x!=n;x=fa[x]) {
		if(ok[x]) break;
		ok[x] = 1;
		upd(dfn[x], 1);
		upd(dfn[x]+sz[x], -1);
		++cnt;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for(int i=1;i<n;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	dfs(n, 0); ok[n] = 1;
	for(int i=n-1;i>=1;i--) if(!ok[i]) calc(i);
	for(int i=1;i<=n;i++) if(!ok[i]) printf("%d ", i);
	return 0;
}