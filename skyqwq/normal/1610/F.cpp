// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

struct E{
	int u, v, w;
};

namespace S1{
	const int MAXN=6e5+50,MAXM=2e6+50;

	struct edge{int nxt,to,val,ans;};

	edge e[MAXM];//e[i].nxt 
	int head[MAXN],Cnte=1;//head[i]i 
	int nxt[MAXM],now[MAXN][3];//nxt[i]now[i][j]ij 
	int N,M,deg[MAXN];

	void adde(int u,int v,int w){
		++Cnte;
		e[Cnte]=(edge){head[u],v,w,-1};
		nxt[Cnte]=now[u][w];
		now[u][w]=head[u]=Cnte;
	}

	void dfs(int u,int pre){
		while(now[u][pre]&&e[now[u][pre]].ans!=-1) now[u][pre]=nxt[now[u][pre]];// 
		if(!now[u][pre]){pre=(pre==1?2:1);while(now[u][pre]&&e[now[u][pre]].ans!=-1) now[u][pre]=nxt[now[u][pre]];}// 
		if(!now[u][pre]) return;
		e[now[u][pre]].ans=0;e[now[u][pre]^1].ans=1; 
		int t=now[u][pre];
		now[u][pre]=nxt[now[u][pre]];
		dfs(e[t].to,pre);
		for(int i=head[u];i;i=e[i].nxt){
			head[u]=e[i].nxt;
			if(e[i].ans==-1){e[i].ans=0;e[i^1].ans=1;dfs(e[i].to,e[i].val);}
		}
	}
	void Solve(){
		for(int i=1;i<=N;++i) if(deg[i]&1){adde(N+1,i,1);adde(i,N+1,1);}// 
		dfs(1,1);
	}
	void Init(int n, int m, vector<E> t){
		Cnte=1;
		N=n;M=m;
		for(E x: t){
			int u=x.u,v=x.v,w=x.w;
			adde(u,v,w);adde(v,u,w);
			++deg[u];++deg[v];
		}
		Solve();
	}

	

	vector<int> Print(){
		vector<int> res;
		for(int i=1;i<=M;++i) res.pb(e[i<<1].ans + 1);
		return res;
	}
}

const int N = 6e5 + 5;

int n, m, sm, faW[N], dep[N], deg[N], idx, id[N];
 
E e[N];

vector<PII> g[N];

bool vis[N], st[N];

int fa[N], ans[N];

void add(int u, int v) {
	while (u != v) {
		if (dep[u] > dep[v]) {
			int now = faW[u];
			ans[now] = e[now].v == fa[u] ? 1 : 2;
			u = fa[u];
		} else {
			int now = faW[v];
			ans[now] = e[now].v == v ? 1 : 2;
			v = fa[v];
		}
	}
}
int nm = m;
int dfs(int u) {
	vis[u] = 1;
	if (!deg[u]) {
		++sm;
		e[++nm] = (E) { ++idx, u, 1 };
	}
	int now = deg[u] == 0 ? u : 0;
	for (PII t: g[u]) {
		int v = t.fi;
		if (vis[v]) continue;
		if (v == fa[u]) continue;
		fa[v] = u, faW[v] = t.se;
		dep[v] = dep[u] + 1;
		int o = dfs(v);
		if (o) {
			//if (now) add(now, o), now = 0;
			//else now = o;
		}
	}
	return now;
}

int main() {
	read(n), read(m); idx = n;
	nm = m;
	for (int i = 1; i <= m; i++) {
		int u, v, w; read(u), read(v), read(w);
		e[i] = (E) { u, v, w };
		if (w == 1) g[u].pb(mp(v, i)), g[v].pb(mp(u, i)), deg[u] ^= 1, deg[v] ^= 1;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			int p = dfs(i);
		}
	}

	vector<E> t;
	for (int i = 1; i <= nm; i++) {
		if (!ans[i]) t.pb(e[i]), id[t.size() - 1] = i;
	}
	S1::Init(idx, nm, t);
	vector<int> ret = S1::Print();
	for (int i = 0; i < ret.size(); i++) ans[id[i]] = ret[i];
	printf("%d\n", n - sm);
	for (int i = 1; i <= m; i++) printf("%d", ans[i]);
    return 0;
}