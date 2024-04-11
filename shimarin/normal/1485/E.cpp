#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cout<<i<<" ";puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
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

const int N = 2e5+10;
int n,a[N];
poly e[N],v[N];
ll f[N],g[N];

int mx,dep[N],fa[N];
inline void dfs(int u){
	dep[u]=dep[fa[u]]+1,mx=max(mx,dep[u]);
	for (auto v:e[u]) if (v!=fa[u]){
		fa[v]=u,dfs(v);
	}
}
inline void solve(){
	n=read();
	For(i,1,n) e[i].clear(),fa[i]=0,f[i]=g[i]=0,v[i].clear();
	For(i,2,n){
		int x=read();
		e[x].pb(i),e[i].pb(x);
	}
	For(i,2,n) a[i]=read();
	mx=0,dfs(1);
	For(i,1,n) v[dep[i]].pb(i);
	Dow(i,mx,1){
		sort(all(v[i]),[](int x,int y){
			return a[x]<a[y];
		});
		for (auto j:v[i]){
			for (auto k:e[j]) if (dep[k]==i+1) g[j]=max(g[j],f[k]); 
			f[j]=g[j]+max(a[j]-a[v[i][0]],a[v[i].back()]-a[j]);
		}
		ll mx=g[v[i][0]]-a[v[i][0]];
		FOR(j,1,siz(v[i])){
			f[v[i][j]]=max(f[v[i][j]],mx+a[v[i][j]]);
			mx=max(mx,g[v[i][j]]-a[v[i][j]]);
		}
		mx=g[v[i].back()]+a[v[i].back()];
		Dow(j,siz(v[i])-2,0){
			f[v[i][j]]=max(f[v[i][j]],mx-a[v[i][j]]);
			mx=max(mx,g[v[i][j]]+a[v[i][j]]);
		}
	}
	printf("%lld\n",f[1]);
}

int main(){
	int T=read();
	while (T--) solve();
}