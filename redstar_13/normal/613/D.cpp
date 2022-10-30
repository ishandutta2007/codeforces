#include<bits/stdc++.h>

#define inf 0x3f3f3f3f
#define pb emplace_back
#define x first
#define y second
#define bctz(x) (__builtin_ctz(x))

using namespace std;

typedef long long INT;
typedef pair<int, int> pii;
typedef vector<int> VI;

template<typename T, typename U> inline void smin(T &a, U b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, U b) {if(a<b) a=b;}

template<class T>inline void gn(T &x) {char c, sg=0; while (c=getchar(), (c>'9' || c<'0') && c!='-');for((c=='-'?sg=1, c=getchar():0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0';if (sg) x=-x;}
template<class T>inline void print(T x) {if (x<0) {putchar('-');return print(-x);}if (x<10) {putchar('0'+x);return;} print(x/10);putchar(x%10+'0');}
template <class T> inline void println(T x) {print(x); putchar('\n');}

#define NN 100111

int p[NN][22], deep[NN];
int ID[NN];
int id;
VI adj[NN];
int n, q;
int k;
int node[NN];

struct LCA {
	void dfs(int u, int fa=0){
		p[u][0]=fa;
		ID[u] = ++id;
		deep[u]=deep[fa]+1;
		for(int i=1; i<18; i++) p[u][i]=p[p[u][i-1]][i-1];
		for(int v : adj[u]) {
			if(v==fa) continue;
			dfs(v, u);
		}
	}
	int k_th(int u, int k){
		for(; k; ) u = p[u][bctz(k&-k)], k-=k&-k;
		return u;
	}
	int lca(int a, int b){
		if(deep[a]>deep[b]) swap(a, b);
		b=k_th(b, deep[b]-deep[a]);
		if(a==b) return a;
		for(int i=17; i>=0; i--){
			if(p[a][i]!=p[b][i]) a=p[a][i], b=p[b][i];
		}
		return p[a][0];
	}
} lca;

int vst[NN];
int runs;
int flag[NN];
INT dp[NN][2];

struct Tree{
	VI adj[NN];
	int st[NN];
	int top;
	
	inline void add(int u, int v) {
//		cerr<<u<<' '<<v<<endl;
		if(vst[u] != runs) adj[u].clear();
		vst[u] = runs;
		adj[u].pb(v);
	}
	
	inline void del(int u) {
		adj[u].pop_back();
	}
	
	inline void build() {
		sort(node, node+k, [](int u, int v) {return ID[u] < ID[v];});
		top=0;
		for(int i=0; i<k; i++) {
			int u=node[i];
			flag[u] = runs;
			if(top == 0) {st[++top] = u; continue;}
			int pre=-1;
			int v=lca.lca(u, st[top]);
			while(top and deep[st[top]] >= deep[v]) pre=st[top--];
			if(pre==v) add(v, u);
			else {
				del(st[top]);
				add(st[top], v);
				add(v, pre);
				add(v, u);
			}
			st[++top] = v;
			st[++top] = u;
		}
	}
	
	INT dfs(int u) {
		if(flag[u] == runs) {
			dp[u][0] = inf;
			dp[u][1] = 0;
			for(int v : adj[u]) {
				dfs(v);
				dp[u][1] += min(dp[v][0], dp[v][1]+1);
			}
		} else {
			dp[u][0]=0;
			dp[u][1]=0;
			int tmp;
			INT res=0;			
			INT mn=0x3f3f3f3f3f3f3f3fLL;
			for(int v : adj[u]) {
				dfs(v);
				tmp = min(dp[v][0], dp[v][1]+1);
				smin(mn, dp[v][1]-tmp);
				dp[u][0] += tmp;
				res += min(dp[v][0], dp[v][1]);
			}
			dp[u][1] = dp[u][0] + mn;
			smin(dp[u][0], res+1);
		}
		smin(dp[u][1], inf);
		smin(dp[u][0], inf);
//		cerr<<u<<' '<<dp[u][0]<<' '<<dp[u][1]<<endl;
		return min(dp[u][0], dp[u][1]);
	}
	
} tree;
int solve() {
	gn(k);
	for(int i=0; i<k; i++) gn(node[i]);
	if(k==1) return 0;
	runs++;
	for(int i=0; i<k; i++) vst[node[i]] = runs;
	for(int i=0; i<k; i++) {
		if(vst[p[node[i]][0]] == runs) return -1;
	}
	runs++;
	tree.build();
	return tree.dfs(tree.st[1]);
}

void jiejue() {
	cin >> n;
	for(int i=0; i<n-1; i++) {
		int u, v; gn(u); gn(v);
		adj[u].pb(v); adj[v].pb(u);
	}
	lca.dfs(1);
	cin >> q;
	while(q--) {
		println(solve());
	}
}

int main() {
#ifndef	ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	jiejue();
	return 0;
}