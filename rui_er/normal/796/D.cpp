//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e5+5; 

int n, k, d, a[N], col[N], vis[N];
vector<int> ans;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
struct Node {
	int u, c;
	Node(int a=0, int b=0) : u(a), c(b) {}
	~Node() {}
};
struct Edge {
	int v, nxt, id;
	Edge(int a=0, int b=0, int c=0) : v(a), nxt(b), id(c) {}
	~Edge() {}
}e[N<<1];
int h[N], ne = 1;
void add(int u, int v, int id) {
	e[++ne] = Edge(v, h[u], id); h[u] = ne;
	e[++ne] = Edge(u, h[v], id); h[v] = ne;
}

queue<Node> q;
void bfs() {
	rep(i, 1, k) {
		if(col[a[i]]) continue;
		col[a[i]] = i;
		q.push(Node(a[i], i));
	}
	while(!q.empty()) {
		int u = q.front().u, c = q.front().c; q.pop();
		for(int i=h[u];i;i=e[i].nxt) {
			int v = e[i].v;
			if(!col[v]) {
				col[v] = c;
				q.push(Node(v, c));
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &d);
	rep(i, 1, k) scanf("%d", &a[i]);
	rep(i, 1, n-1) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v, i);
	}
	bfs();
//	rep(i, 1, n) printf("%d%c", col[i], " \n"[i==n]);
	rep(u, 1, n) {
		for(int i=h[u];i;i=e[i].nxt) {
			int v = e[i].v, id = e[i].id;
			if(!vis[id] && col[u] != col[v]) {
				ans.push_back(id);
				vis[id] = 1;
			}
		}
	}
	int sz = ans.size();
	printf("%d\n", sz);
	rep(i, 0, sz-1) printf("%d%c", ans[i], " \n"[i==sz-1]);
	return 0;
}