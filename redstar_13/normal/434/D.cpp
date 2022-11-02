#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define mx 1999728

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}
typedef vector<int> VI;

int a[51], b[51], c[51], l[51], r[51];
int st[51], ed[51];

#define NN 10100
#define MM 60600

struct Dinic {
	int V, E, src, tar;
	int head[NN], work[NN], dis[NN];
	int to[MM], cap[MM], nxt[MM];
	int q[NN], qf, qb;
	
	inline void calc(int n, int m) {
		for(int i=1; i<=n; i++) {
			add(src, st[i], inf);
			for(int j=st[i]; j<ed[i]; j++) {
				int x=j-st[i]+l[i];
				add(j, j+1, mx-a[i]*x*x-b[i]*x-c[i]);
			}
			add(ed[i], tar, inf);
		}
		while(m--) {
			int u, v, d; scanf("%d %d %d", &u, &v, &d);
			for(int i=l[u], j=i-d; i<=r[u]+1; i++, j++) if(l[v]<=j && j<=r[v]+1) {
				add(i-l[u]+st[u], j-l[v]+st[v], inf);
			}
		}
		int ans=n*mx-dinic();
		printf("%d", ans);
	}
	
	inline void init(int n, int s, int t){
		V=n+1; E=0; src=s; tar=t;
		for(int i=0; i<=V; i++) head[i]=-1;
	}
	
	inline void add(int u, int v, int c){
		to[E]=v; cap[E]=c; nxt[E]=head[u]; head[u]=E++;
		to[E]=u; cap[E]=0; nxt[E]=head[v]; head[v]=E++;
	}
	
	inline bool bfs(){
		for(int i=0; i<=V; i++) dis[i]=-1;
		qf=qb=0;
		q[qb++]=src; dis[src]=0;
		while(qf<qb && dis[tar]==-1){
			int u=q[qf++];
			for(int i=head[u]; i>=0; i=nxt[i]){
				int v=to[i];
				if(dis[v]==-1 && cap[i]>0){
					dis[v]=dis[u]+1;
					q[qb++]=v;
				}
			}
		}
		return dis[tar]>=0;
	}

	inline int dfs(int u, int &bot){
		int v, bot1, delta;
		if(u==tar) return bot;
		for(int &i=work[u]; i>=0; i=nxt[i]){
			int v=to[i];
			if(dis[v]!=dis[u]+1 || cap[i]==0) continue;
			bot1=min(bot, cap[i]);
			if(delta=dfs(v, bot1)){
				cap[i]-=delta;
				cap[i^1]+=delta;
				bot=bot1;
				return delta;
			}
		}
		return 0;
	}

	inline int dinic(){
		int ans=0, delta, bot;
		while(bfs()){
			memcpy(work, head, sizeof(int)*V);
			delta=inf;
			while(delta=dfs(src, bot=inf)) ans+=delta;
		}
		return ans;
	}
} dinic;

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int n, m, cur=0; scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d %d %d", a+i, b+i, c+i);
	for(int i=1; i<=n; i++) {
		scanf("%d %d", l+i, r+i);
		st[i]=cur;
		cur+=r[i]-l[i]+1;
		ed[i]=cur++;
	}
	int src=cur++, tar=cur++;
	dinic.init(cur, src, tar);
	dinic.calc(n, m);
}