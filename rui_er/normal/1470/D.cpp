//By: Luogu@rui_er(122461)
//virtual participation
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int T, n, m, vis[N];
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Edge {
	int v, nxt;
	Edge(int a=0, int b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
int ne = 1, h[N];
void add(int u, int v) {
	e[++ne] = Edge(v, h[u]); h[u] = ne;
	e[++ne] = Edge(u, h[v]); h[v] = ne;
}
void dfs(int u, int f) {
	int ok = 1;
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(vis[v] == 1) {ok = 0; break;}
	}
	vis[u] = ok;
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(v != f && vis[v] == -1) dfs(v, u);
	}
}

int main() {
	for(scanf("%d", &T);T;T--) {
		scanf("%d%d", &n, &m);
		rep(i, 1, ne) e[i].v = e[i].nxt = 0;
		rep(i, 1, n) h[i] = 0, vis[i] = -1; ne = 1;
		rep(i, 1, m) {
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
		}
		dfs(1, 0);
		int s = 0, ok = 1;
		rep(i, 1, n) {
			if(vis[i] == -1) {ok = 0; break;}
			s += vis[i];
		}
		if(!ok) puts("NO");
		else {
			puts("YES");
			printf("%d\n", s);
			rep(i, 1, n) if(vis[i] == 1) printf("%d%c", i, " \n"[i==n]);
		}
	}
	return 0;
}