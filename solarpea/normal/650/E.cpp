//testing code from luogu tijie
#include <bits/stdc++.h>
using namespace std;
struct graph {
	struct edge {
	    int v,nxt;
	}ed[1000010];
	int head[500010],cnt;
	void add(int u,int v) {
		ed[++cnt] = (edge){v,head[u]};
		head[u] = cnt;
	}
	int fa[500010];
	void dfs(int x,int f) {
		fa[x] = f;
		for (int i = head[x];i;i = ed[i].nxt)
			if (ed[i].v != f) dfs(ed[i].v,x);
	}
}g1,g2;
int fa[500010];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int read() {
	int s = 0,f = 1;char ch = getchar();
	while (!isdigit(ch)) f = ch == '-' ? -1 : 1, ch = getchar();
	while (isdigit(ch)) s = s * 10 + ch - '0', ch = getchar();
	return s*f;
}
struct ans {
	int x,y,u,v;
}a[1000010];
int cnt;
void dfs(int x,int f) {
	for (int i = g1.head[x];i;i = g1.ed[i].nxt) {
		int v = g1.ed[i].v;
		if (v == f) continue;
		dfs(v,x);
		if (find(v) != find(x)) a[++cnt] = {x,v,find(v),g2.fa[find(v)]},fa[find(v)]=g2.fa[find(v)];//
	}
}
int main() {
	int n = read();
	for (int i = 1,u,v;i < n;i ++ ) u = read(), v = read(), g1.add(u,v), g1.add(v,u);
	for (int i = 1,u,v;i < n;i ++ ) u = read(), v = read(), g2.add(u,v), g2.add(v,u);
	g1.dfs(1,0), g2.dfs(1,0);
	fa[1] = 1;
	for (int i = 2;i <= n;i ++ ) {
		int f = g2.fa[i];
		if (g1.fa[f] == i || g1.fa[i] == f) fa[i] = f;//
		else fa[i] = i;
	}
	dfs(1,0);
	printf("%d\n",cnt);
	for (int i = 1;i <= cnt;i ++ ) printf("%d %d %d %d\n",a[i].x,a[i].y,a[i].u,a[i].v);
	return 0;
}