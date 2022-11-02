#include<bits/stdc++.h>

#define x first
#define y second
#define pb push_back

using namespace std;

typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

template<typename T, typename U> inline void smin(T &a, const U &b) {if(a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if(a<b) a=b;}

template <class T> inline void gn(T &x) {char c, sg=0; while(c=getchar(), (c>'9' || c<'0') && c!='-'); for((c=='-' ? sg=1, c=getchar() : 0), x=0; c>='0' && c<='9'; c=getchar()) x=(x<<1)+(x<<3)+c-'0'; if(sg) x=-x;}
template <class T1, class T2> inline void gn(T1 &x1, T2 &x2) {gn(x1), gn(x2);}
int power(int a, int b, int m, int ans=1){for (; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m; return ans;}

#define NN 1000100
#define MM 1000099
int root[NN], mx[NN];
int find(int u){
	if(u==root[u]) return u;
	int f=find(root[u]);
	smax(mx[u], mx[root[u]]);
	return root[u]=f;
}

VI adj[NN];
int sz[NN], fa[NN];

typedef pair <pii, int> pi3;
vector <pi3> query[NN];
vector <INT> ans;

int n, vst[NN];
int stk[NN], top;
INT sum[NN];

void dfs(int u){
	vst[u]=1;
	if(u<=n){
		for(pi3 q : query[u]){
			int l=upper_bound(stk+top, stk+MM, q.x.x)-stk;
			int r=upper_bound(stk+top, stk+MM, q.x.y)-stk;
			ans[q.y]=sum[l]-sum[r];
		}
	}
	if(adj[u].size()==1){
		stk[--top]=u-n;
		sum[top]=sum[top+1]+sz[u];
	}
	for(int v : adj[u]) dfs(v);
	if(adj[u].size()==1) top++;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int m;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) root[i]=i, fa[i]=i, sz[i]=1;
	
	char tp;
	int u, v;
	for(int i=1; i<=m; i++){
		scanf(" %c", &tp), gn(u);
		if(tp=='U'){
			gn(v);
			sz[n+i]=sz[fa[u]]+sz[fa[v]];
			adj[n+i].pb(fa[u]);
			adj[n+i].pb(fa[v]);
			fa[u]=n+i;
		}
		else if(tp=='M'){
			gn(v);
			root[find(u)]=n+i;
			root[find(v)]=n+i;
			root[n+i]=n+i;
		}
		else if(tp=='A'){
			sz[n+i]=sz[fa[u]];
			adj[n+i].pb(fa[u]);
			fa[u]=n+i;
		}
		else if(tp=='Z'){
			mx[find(u)]=i;
		}
		else {
			find(u);
			query[u].pb(pi3(pii(mx[u], i), ans.size()));
			ans.pb(0);
		}
	}
	
	for(int i=n+m; i; i--) if(!vst[i]) top=MM, dfs(i);
	
	for(INT x : ans) printf("%I64d\n", x);
	
	return 0;
}