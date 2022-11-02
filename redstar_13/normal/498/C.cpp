#include<bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}

int power(int a, int b, int m, int ans=1) {
	for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
	return ans;
}

#define NN 120
#define MM 420
#define inf 1000000000

int V, E, src, tar;
int head[NN], work[NN], dis[NN];
int to[MM], cap[MM], nxt[MM];
int q[NN], qf, qb;

void init(int n, int s, int t){
	V=n; E=0; src=s; tar=t;
	memset(head, -1, sizeof(int)*V);
}

void add_edge(int u, int v, int c){
	to[E]=v; cap[E]=c; nxt[E]=head[u]; head[u]=E++;
	to[E]=u; cap[E]=0; nxt[E]=head[v]; head[v]=E++;
}

bool bfs(){
	memset(dis, -1, sizeof(dis));
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

int dfs(int u, int &bot){
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

int dinic(){
	int ans=0, delta, bot;
	while(bfs()){
		memcpy(work, head, sizeof(int)*V);
		delta=inf;
		while(delta=dfs(src, bot=inf)) ans+=delta;
	}
	return ans;
}

pii good[NN];
int a[NN];
vector<int> res;

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	int n, m;
	gn(n, m);
	
	for(int i=1; i<=n; i++) {
		gn(a[i]);
		int x = a[i];
		for(int j=2; j*j<=x; j++) if(x % j == 0){
			while(x % j == 0) x /= j;
			res.push_back(j);
		}
		if(x > 1) res.push_back(x);
	}
	
	for(int i=1; i<=m; i++) gn(good[i].x, good[i].y);
	
	sort(res.begin(), res.end());
	res.resize(unique(res.begin(), res.end()) - res.begin());
	
	int src = n + 1;
	int tar = src + 1;
	int ans = 0;
	
	for(auto u : res) {
		init(tar + 10, src, tar);
		for(int i=1; i<=n; i++) {
			int s = 0;
			while(a[i] % u == 0) a[i] /= u, s++;
			if(i % 2) add_edge(src, i, s);
			else add_edge(i, tar, s);
		}
		for(int i=1; i<=m; i++) {
			int u = good[i].x, v = good[i].y;
			if(u % 2 == 0) swap(u, v);
			add_edge(u, v, inf);
		}
		ans += dinic();
	}
	
	cout<<ans<<endl;
}