//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+5; 

int n, col[N], cnt[3];
struct Edge {
	int v, nxt;
	Edge() {}
	Edge(int a, int b) : v(a), nxt(b) {}
	~Edge() {}
}e[N<<1];
int ne, h[N];
void add(int u, int v) {
	e[++ne] = Edge(v, h[u]);
	h[u] = ne;
	e[++ne] = Edge(u, h[v]);
	h[v] = ne;
}
void dfs(int u, int c) {
	++cnt[col[u]=c];
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(!col[v]) dfs(v, 3-c);
	}
}

int main() {
	scanf("%d", &n);
	for(int i=1;i<n;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
	}
	dfs(1, 1);
	printf("%d\n", min(cnt[1], cnt[2])-1);
	return 0;
}