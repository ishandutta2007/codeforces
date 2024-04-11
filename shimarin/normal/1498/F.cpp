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

const int N = 1e5+10;
int n,k,a[N];
poly e[N];

int f[N][45];
inline void dfs(int u,int fa){
	for (auto v:e[u]) if (v!=fa){
		dfs(v,u);
		FOR(i,0,2*k) f[u][(i+1)%(2*k)]^=f[v][i];
	}
	f[u][0]^=a[u];
}
int ans[N];
inline void Dfs(int u,int fa,poly g){
	FOR(i,k,2*k) ans[u]^=g[i]^f[u][i];
	FOR(i,0,2*k) g[i]^=f[u][i];
	poly G(2*k);
	FOR(i,0,2*k) G[(i+1)%(2*k)]^=g[i];
	for (auto v:e[u]) if (v!=fa){
		poly tmp=G;
		FOR(i,0,2*k) tmp[(i+2)%(2*k)]^=f[v][i];
		Dfs(v,u,tmp);
	}
}

int main(){
	n=read(),k=read();
	FOR(i,1,n){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	For(i,1,n) a[i]=read();
	dfs(1,0);
	poly v(2*k);
	Dfs(1,0,v);
	For(i,1,n) printf("%d ",ans[i]>0);
}