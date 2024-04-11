//By: Luogu@rui_er(122461).
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const int N = 3e5+5;

int n, m, s, t, dfn[N], low[N], col[N], ins[N], tms, scc, ok[N];
stack<int> st;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}
struct Edge {
	int v, w, nxt;
	Edge(int a=0, int b=0, int c=0) : v(a), w(b), nxt(c) {}
	~Edge() {}
};
struct Graph {
	Edge e[N<<1];
	int h[N], ne;
	Graph() : ne(1) {
		memset(e, 0, sizeof(e));
		memset(h, 0, sizeof(h));
	}
	void add(int u, int v, int w) {
		e[++ne] = Edge(v, w, h[u]); h[u] = ne;
		e[++ne] = Edge(u, w, h[v]); h[v] = ne;
	}
}G, SCC;
#define forall(G,u) for(int i=G.h[u];i;i=G.e[i].nxt) {int v = G.e[i].v, w = G.e[i].w;
#define end }
void tarjan(int u, int f) {
	dfn[u] = low[u] = ++tms;
	ins[u] = 1;
	st.push(u);
	forall(G, u)
		if(v == f) continue;
		if(!dfn[v]) {
			tarjan(v, u);
			chkmin(low[u], low[v]);
		}
		else if(ins[v]) chkmin(low[u], dfn[v]);
	end
	if(dfn[u] == low[u]) {
		++scc;
		while(true) {
			int v = st.top(); st.pop();
			ins[v] = 0;
			col[v] = scc;
			if(u == v) break;
		}
	}
}
bool dfs(int u, int f, bool now) {
	now |= ok[u];
	if(u == t) {
		puts(now?"YES":"NO");
		return 1;
	}
	forall(SCC, u)
		if(v != f) {
			if(dfs(v, u, now|w)) return 1;
		}
	end
	return 0;
}

int main() {
	scanf("%d%d", &n, &m);
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G.add(u, v, w);
	}
	rep(i, 1, n) if(!dfn[i]) tarjan(i, 0);
	rep(u, 1, n) {
		forall(G, u)
			if(i & 1) continue; 
			if(col[u] == col[v] && w) ok[col[u]] = 1;
			if(col[u] != col[v]) SCC.add(col[u], col[v], w);
		end
	}
	scanf("%d%d", &s, &t);
	s = col[s]; t = col[t];
	dfs(s, 0, 0);
    return 0;
}