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

#define NN 300
#define MM 41000
#define inf 1000000000

int V, E, src, tar;
int head[NN], work[NN], dis[NN];
int to[MM], cap[MM], nxt[MM];
int q[NN], qf, qb;
int id[NN][NN];

void init(int n, int s, int t){
	V=n; E=0; src=s; tar=t;
	memset(head, -1, sizeof(int)*V);
}

void add_edge(int u, int v, int c){
	id[u][v] = E, id[v][u] = E+1;
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

int p[21000];
int a[NN];

inline int is_prime(int u) {
	for(int i=2; i*i<=u; i++) if(u % i == 0) return 0;
	return 1;
}

vector<int> adj[NN];
vector<int> ans[NN];
int flag[NN];

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	for(int i=2; i<21000; i++) p[i] = is_prime(i);
	
	int n; gn(n);
	for(int i=1; i<=n; i++) gn(a[i]);
	
	int src = n + 1, tar = src + 1;
	
	init(tar+10, src, tar);
	
	for(int i=1; i<=n; i++) {
		if(a[i] % 2) add_edge(src, i, 2);
		else add_edge(i, tar, 2);
	}
	
	for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) if(p[a[i]+a[j]]) {
		int u = i, v = j;
		if(a[u] % 2 == 0) swap(u, v);
		add_edge(u, v, 1);
	}
	
	if(dinic() != n) return puts("Impossible"), 0;
	
	for(int i=1; i<=n; i++) for(int j=i+1; j<=n; j++) if(p[a[i]+a[j]]){
		int u = i, v = j;
		if(a[u] % 2 == 0) swap(u, v);
		if(!cap[id[u][v]]) {
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}
	
	int nn = 0;
	
	for(int i=1; i<=n; i++) if(!flag[i]) {
		int x = adj[i][0];
		ans[nn].push_back(i);
		int pos = x;
		flag[i] = 1;
		while(1) {
			ans[nn].push_back(pos);
			flag[pos] = 1;
			int u = adj[pos][0], v = adj[pos][1];
			if(!flag[u]) pos = u;
			else if(!flag[v]) pos = v;
			else break;
		}
		nn++;
	}
	
	cout<<nn<<endl;
	
	for(int i=0; i<nn; i++) {
		printf("%d ", ans[i].size());
		for(auto x : ans[i]) printf("%d ", x);
		puts("");
	}
}