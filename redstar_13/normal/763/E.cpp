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

#define NN 100100
VI adj[NN];
int vst[NN], sum[NN], rid;

void dfs(int u){
	vst[u]=++rid;
	for(int v : adj[u]) if(!vst[v]) dfs(v);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif
	
	int n, k, m;
	cin >> n >> k >> m;
	for(int i=0; i<m; i++){
		int u, v; gn(u, v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	for(int i=1; i<=n; i++){
		sum[i]=sum[i-1];
		if(!vst[i]) dfs(i), sum[i]++;
	}
	
	cin >> m;
	while(m--){
		int l, r, x; gn(l, r);
		int ans=sum[r]-sum[l-1];
		for(x=l; x<=min(r, l+k); x++) if(!(sum[x]-sum[x-1])){
			int ok=1;
			for(int y : adj[x]) if(y>=l && y<=r && vst[y]<vst[x]){ok=0; break;}
			ans+=ok;
		}
		for(smax(x, r-k); x<=r; x++) if(!(sum[x]-sum[x-1])){
			int ok=1;
			for(int y : adj[x]) if(y>=l && y<=r && vst[y]<vst[x]){ok=0; break;}
			ans+=ok;
		}
		printf("%d\n", ans);
	}
	
	return 0;
}