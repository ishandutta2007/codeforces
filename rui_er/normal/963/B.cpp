//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int (x)=(y);(x)<=(z);(x)++)
#define per(x,y,z) for(int (x)=(y);(x)>=(z);(x)--)
#define fil(x,y) memset((x), (y), sizeof(x))
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, deg[N], fa[N], vis[N], ans[N], tot;
stack<int> s;
struct Edge {
	int v, nxt;
	Edge(int a=0, int b=0) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
int ne, h[N];
void add(int u, int v) {
	if(!u || !v) return;
	e[++ne] = Edge(v, h[u]); h[u] = ne; ++deg[u];
	e[++ne] = Edge(u, h[v]); h[v] = ne; ++deg[v];
}
void dfs(int u, int f) {
	fa[u] = f;
	s.push(u);
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(v != f) dfs(v, u);
	}
}
void dfs2(int u, int f) {
	vis[u] = 1; ans[++tot] = u;
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		--deg[v];
		if(v != f && !vis[v] && !(deg[v] & 1)) dfs2(v, u);
	}
}

int main() {
	scanf("%d", &n);
	if(!(n & 1)) return puts("NO"), 0;
	rep(i, 1, n) {int _; scanf("%d", &_); add(i, _);}
	dfs(1, 0);
	while(!s.empty()) {
		int u = s.top(); s.pop();
		if(!(deg[u] & 1)) dfs2(u, fa[u]);
	}
	if(tot == n) {
		puts("YES");
		rep(i, 1, n) printf("%d\n", ans[i]);
	}
	else puts("NO");
    return 0;
}