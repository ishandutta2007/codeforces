#include<bits/stdc++.h>
#define pb push_back
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

#define inf 0x3f3f3f3f
#define NN 101010
#define MM 4040404

int UU[660], VV[660], deg[660];
vector<int> vec[660];
int c[660];

struct Dinic {
	int head[NN], work[NN], dis[NN];
	int to[MM], cap[MM], nxt[MM];
	int q[NN], qf, qb;
	int V, E, src, tar;
	inline void init(int n, int s, int t) {
		V=n+1, E=0, src=s, tar=t;
		for(int i=0; i<=V; i++) head[i]=-1;
	}
	inline void add(int u, int v, int c) {
		to[E]=v, cap[E]=c, nxt[E]=head[u], head[u]=E++;
		to[E]=u, cap[E]=0, nxt[E]=head[v], head[v]=E++;
	}
	bool bfs() {
		for(int i=0; i<=V; i++) dis[i]=-1;
		qf=qb=0; int u, v, e;
		q[qb++]=src; dis[src]=0;
		while(qf<qb && !~dis[tar]) {
			u=q[qf++];
			for(e=head[u]; ~e; e=nxt[e]) {
				v=to[e];
				if(!~dis[v] && cap[e]>0) {
					dis[v]=dis[u]+1;
					q[qb++]=v;
				}
			}
		}
		return ~dis[tar];
	}
	int dfs(int u, int &bot) {
		int v, bot1, delta;
		if(u==tar) return bot;
		for(int &e=work[u]; ~e; e=nxt[e]) {
			v=to[e];
			if(dis[v]!=dis[u]+1 || !cap[e]) continue;
			bot1=min(bot, cap[e]);
			if(delta=dfs(v, bot1)) {
				cap[e]-=delta;
				cap[e^1]+=delta;
				bot=bot1;
				return delta;
			}
		}
		return 0;
	}
	inline int dinic() {
		int ans=0, delta, bot;
		while(bfs()) {
			memcpy(work, head, sizeof(int)*V);
			delta=inf;
			while(delta=dfs(src, bot=inf)) ans+=delta;
		}
		return ans;
	}
	
	inline void solve() {
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		for(int i=1; i<=n; i++) {
			deg[i]=0;
			vec[i].clear();
		}
		for(int i=1; i<=m; i++) {
			scanf("%d %d", UU+i, VV+i);
			deg[UU[i]]++, deg[VV[i]]++;
			c[i]=0;
		}
		int src=0, tar=n+m+1;
		init(tar+100, src, tar);
		for(int i=1; i<=m; i++) {
			add(UU[i], n+i, 1);
			add(VV[i], n+i, 1);
		}
		int sum=0;
		bool can=true;
		for(int i=1; i<=n; i++) if(deg[i]>k) {
			if(deg[i]>k<<1) {can=false; break;}
			add(src, i, deg[i]-k<<1);
			sum+=deg[i]-k<<1;
		}
		if(!can) {
			for(int i=1; i<=m; i++) printf("0 ");
			puts(""); return ;
		}
		for(int i=1; i<=m; i++) add(n+i, tar, 1);
		
		if(dinic()==sum) {
			for(int i=1; i<=m; i++) {
				if(cap[4*i-3]) vec[UU[i]].pb(i);
				if(cap[4*i-1]) vec[VV[i]].pb(i);
			}
			int N=0;
			for(int u=1; u<=n; u++) {
				for(int i=0; i<vec[u].size(); i+=2) {
					c[vec[u][i]]=c[vec[u][i+1]]=++N;
				}
			}
			for(int i=1; i<=m; i++) {
				if(c[i]) printf("%d ", c[i]);
				else printf("%d ", ++N);
			}
			puts("");
		}
		else {
			for(int i=1; i<=m; i++) printf("0 ");
			puts("");
		}
	}
} dinic;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int T; scanf("%d", &T);
	while(T--) dinic.solve();
}