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

#define NN 300300
int ch[NN][26];
char s[NN];
int val[NN], id[NN], sz[NN];
VI adj[NN];

int cur;
int nxt(int p, char c){
	if(!ch[p][c-'a']) ch[p][c-'a']=++cur;
	return ch[p][c-'a'];
}

int L[NN], R[NN], rec[NN], rid;
void dfs(int u, int f=0, int p=0){
	id[u]=nxt(p, s[u]);
	sz[u]=1;
	rec[rid]=u;
	L[u]=rid++;
	for(int v : adj[u]){
		if(v==f) continue;
		dfs(v, u, id[u]);
		sz[u]+=sz[v];
	}
	R[u]=rid;
}

pii ans;
int tot, cnt[NN];

void redfs(int u, int f=0){
	int son=0;
	for(int v : adj[u]){
		if(v==f) continue;
		if(sz[v]>sz[son]) son=v;
	}
	for(int v : adj[u]){
		if(v==f || v==son) continue;
		redfs(v, u);
		for(int i=L[v]; i<R[v]; i++){
			int w=rec[i];
			if(!--cnt[id[w]]) tot--;
		}
	}
	if(son) redfs(son, u);
	for(int v : adj[u]){
		if(v==f || v==son) continue;
		for(int i=L[v]; i<R[v]; i++){
			int w=rec[i];
			if(!cnt[id[w]]++) tot++;
		}
	}
	if(!cnt[id[u]]++) tot++;
	val[u]+=tot;
	
	if(ans.x==val[u]) ans.y++;
	else if(ans.x<val[u]) ans=pii(val[u], 1);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++) gn(val[i]);
	scanf("%s", s+1);
	
	for(int i=1; i<n; i++){
		int u, v; gn(u, v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfs(1);
	redfs(1);
	
	printf("%d\n%d\n", ans.x, ans.y);
	
	return 0;
}