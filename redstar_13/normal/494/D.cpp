#include<bits/stdc++.h>
#define max_sq_len 18
#define mod 1000000007
#define INPUT_LEN 1000
#define pb push_back
#define NN 100001
#define y second
#define x first

using namespace std;
typedef long long INT;
typedef pair<int, int> pii;
char gchar(){static char tbuf1[INPUT_LEN],*tmp_st=tbuf1,*tmp_ed=tbuf1;if(tmp_st==tmp_ed){int len=fread(tbuf1,1,INPUT_LEN,stdin);if(len==0)return-1;tmp_ed=tbuf1+len;tmp_st=tbuf1;}return*(tmp_st++);}
inline bool gn(int&x){char c,sg=0;while(c=gchar(),(c>'9'||c<'0')&&c!='-'&&~c);if(c==-1)return 0;for((c=='-'?sg=1,c=gchar():0),x=0;c>='0'&&c<='9';c=gchar())x=(x<<1)+(x<<3)+c-'0';if(sg)x=-x;return 1;}
inline void print(int x){if(x<0){putchar('-');return print(-x);}if(x<10){putchar('0'+x);return;}print(x/10);putchar(x%10+'0');}
template<class T>inline void println(T x){print(x);putchar('\n');}

int n, S, S2;
vector<pii> adj[NN];
int sum[NN], sum2[NN];
int in_sum[NN], in_sum2[NN];
int out_sum[NN], out_sum2[NN];
int add[NN], add2[NN], sz[NN];

INT dp[NN];
int deep[NN], st[NN], ed[NN], dfn[NN], cur, nn;
int vst[NN], seq[NN<<1], rec[NN<<1], mn[NN<<1][max_sq_len];

inline void pre() {
	for(int i=0; i<nn; i++) mn[i][0]=seq[i];
	for(int j=1; j<max_sq_len; j++) for(int i=0; i<nn; i++) {
		mn[i][j]=min(mn[i][j-1], mn[min(nn, i+(1<<j-1))][j-1]);
	}
	for(int i=1; i<=n; i++) {
		out_sum[i]=sum[i]-in_sum[i];
		if(out_sum[i]<0) out_sum[i]+=mod;
		
		out_sum2[i]=sum2[i]-in_sum2[i];
		if(out_sum2[i]<0) out_sum2[i]+=mod;
	}
}

inline int lca(int u, int v) {
	if(vst[u]>vst[v]) swap(u, v);
	int l=31-__builtin_clz(vst[v]-vst[u]+1);
	int id=min(mn[vst[u]][l], mn[vst[v]-(1<<l)+1][l]);
	return rec[id];
}

inline int dist(int u, int v) {
	int w=lca(u, v);
	return (dp[u]+dp[v]-(dp[w]<<1))%mod;
}

inline void dfs(int u, int fa=0) {
	sz[u]=1;
	vst[u]=nn, rec[nn]=u, seq[nn++]=vst[u];
	dfn[u]=++cur;
	st[u]=cur;
	for(pii e: adj[u]) {
		int v=e.x, w=e.y;
		if(v!=fa) {
			deep[v]=deep[u]+1;
			dp[v]=dp[u]+w;
			dfs(v, u);
			rec[nn]=u, seq[nn++]=vst[u];
			
			sz[u]+=sz[v];
			
			add[v]=(in_sum[v]+(INT)w*sz[v])%mod;
			in_sum[u]=(in_sum[u]+add[v])%mod;
			
			add2[v]=(((INT)w*sz[v] + (in_sum[v]<<1))%mod*w + in_sum2[v])%mod;
			in_sum2[u]=(in_sum2[u]+add2[v])%mod;
		}
	}
	ed[u]=cur;
}

inline void rdfs(int u, int fa=0) {
	for(pii e: adj[u]) {
		int v=e.x, w=e.y;
		if(v!=fa) {
			S=(sum[u]-add[v]+mod)%mod;
			S2=(sum2[u]-add2[v]+mod)%mod;
			
			sum[v]=(in_sum[v] + S+(INT)w*(n-sz[v]))%mod;
			sum2[v]=(in_sum2[v] + ((INT)w*(n-sz[v]) + (S<<1))%mod*w + S2)%mod;
			
			rdfs(v, u);
		}
	}
}

int main() {
	gn(n);
	for(int i=1, u, v, w; i<n; i++) {
		gn(u), gn(v), gn(w);
		adj[u].pb({v, w});
		adj[v].pb({u, w});
	}
	
	dfs(1);
	sum[1]=in_sum[1], sum2[1]=in_sum2[1];
	
	rdfs(1);
	pre();
	
	int q, u, v, w, ans; gn(q);
	while(q--) {
		gn(u), gn(v);
		
		w=dist(u, v);
		if(st[v]<=dfn[u] && dfn[u]<=ed[v]) ans=sum2[u] - (((INT)w*(n-sz[v]) + (out_sum[v]<<1))%mod*w + out_sum2[v]<<1)%mod;
		else ans=(((INT)w*sz[v] + (in_sum[v]<<1))%mod*w + in_sum2[v]<<1)%mod - sum2[u];
		println(ans<0 ? ans+mod : ans);
	}
}