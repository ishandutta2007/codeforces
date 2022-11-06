//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 3e3+5;

int n, dfn[N], low[N], inq[N], now;
stack<int> s;
vector<int> circle;
struct Edge {
	int v, w, nxt;
	Edge(int a=0, int b=0, int c=0) : v(a), w(b), nxt(c) {}
	~Edge() {}
}e[N<<2];
int ne = 1, h[N];
void add(int u, int v, int w) {
	e[++ne] = Edge(v, w, h[u]); h[u] = ne;
	e[++ne] = Edge(u, w, h[v]); h[v] = ne;
}
bool tarjan(int u, int f) {
	dfn[u] = low[u] = ++now;
	inq[u] = 1; s.push(u);
	for(int i=h[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if(i == (f ^ 1)) continue;
		if(!dfn[v]) {
			if(tarjan(v, i)) return 1;
			low[u] = min(low[u], low[v]);
		}
		else if(inq[v]) low[u] = min(low[u], dfn[v]);
	}
	if(dfn[u] == low[u]) {
		while(s.top() != u) {
			int t = s.top(); s.pop();
			inq[t] = 0;
			circle.push_back(t);
		}
		inq[u] = 0;
		circle.push_back(u);
		s.pop();
		if(circle.size() > 1) return 1;
		else circle.clear();
	}
	return 0;
}

int dis[N], vis[N];
struct Node {
	int id, dis;
	Node(int a=0, int b=0) : id(a), dis(b) {}
	~Node() {}
	friend bool operator < (const Node &a, const Node &b) {return a.dis > b.dis;}
};
priority_queue<Node> q;
void dijkstra(int s) {
	fil(dis, 0x3f);
	dis[s] = 0; q.push(Node(s, 0));
	while(!q.empty()) {
		int u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i=h[u];i;i=e[i].nxt) {
			int v = e[i].v, w = e[i].w;
			if(dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(Node(v, dis[v]));
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	rep(i, 1, n) {
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v, 1);
	}
	rep(i, 1, n) if(!dfn[i]) if(tarjan(i, 0)) break;
	int sz = circle.size();
	rep(i, 0, sz-1) add(circle[i], n+1, 0);
	dijkstra(n+1);
	rep(i, 1, n) printf("%d%c", dis[i], " \n"[i==n]);
	return 0;
}