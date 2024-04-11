#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
	ll x=0,f=1;char c=getchar();
	while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
	if (c=='-') f=-1,c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}

const int N = 2e5+10, mod = 1e9+7;
int n,a[N];
poly e[N],p[N];

inline int power(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) ret=1ll*ret*a%mod;
	return ret;
}

int h[N],tot,pri[N],phi[N];
inline void init(int n){
	phi[1]=1,h[1]=1;
	For(i,2,n){
		if (!h[i]) h[i]=i,phi[i]=i-1,pri[++tot]=i;
		for (int j=1;j<=tot&&i*pri[j]<=n;++j){
			if (i%pri[j]==0){
				h[i*pri[j]]=h[i],phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
			h[i*pri[j]]=h[i]*pri[j],phi[i*pri[j]]=phi[i]*(pri[j]-1);
		}
	}
}

int Siz,rt,siz[N],mx[N];
bool vis[N];
inline void FindRoot(int u,int fa){
	siz[u]=1,mx[u]=0;
	for (auto v:e[u]) if (v!=fa&&!vis[v]){
		FindRoot(v,u),siz[u]+=siz[v];
		mx[u]=max(mx[u],siz[v]);
	}
	mx[u]=max(mx[u],Siz-siz[u]);
	if (mx[u]<mx[rt]) rt=u;
}
int dep[N];
poly v;
inline void dfs(int u,int fa){
	siz[u]=1,v.pb(u);
	for (auto v:e[u]) if (v!=fa&&!vis[v]){
		dep[v]=dep[u]+1,dfs(v,u),siz[u]+=siz[v];
	}
}
int f[N],ans;
inline void upd(int &x,int y){
	x+=y;
	if (x>=mod) x-=mod;
}
inline void work(int k){
	for (auto i:v) for (auto j:p[a[i]]) upd(f[j],phi[a[i]]);
	for (auto u:v){
		int i=h[a[u]],ret=0;
		for (auto k:p[i]) ret=(ret+1ll*phi[i/k]*f[k])%mod;
		ret=1ll*ret*(a[u]/h[a[u]])%mod;
		ret=1ll*ret*dep[u]%mod;
		ans=(ans+ret*k)%mod;
	}
	for (auto i:v) for (auto j:p[a[i]]) f[j]=0;
}
inline void solve(int u){
	dep[u]=0,dfs(u,0);
	work(1),v.clear();
	for (auto v:e[u]) if (!vis[v]){
		dfs(v,u),work(-1),::v.clear();
	}
	vis[u]=1;
	for (auto v:e[u]) if (!vis[v]){
		rt=0,Siz=siz[v],FindRoot(v,u),solve(rt);
	}
}

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	FOR(i,1,n){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	init(n);
	For(i,1,n) For(j,1,n/i) p[i*j].pb(i);
	rt=0,mx[0]=n,Siz=n,FindRoot(1,0),solve(rt);
	//printf("%d\n",ans);
	ans=(ans+mod)%mod;
	printf("%d\n",2ll*ans*power(1ll*n*(n-1)%mod,mod-2)%mod);
}