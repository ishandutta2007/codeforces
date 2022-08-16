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

const int N = 5010;
int n,k;
poly e[N];

const int mod = 998244353;
inline void upd(int &x,int y){
	x+=y;
	if (x>=mod) x-=mod;
}

int f[N][N],g[N],mx[N],tmp[N];
inline void dfs(int u,int fa){
	f[u][0]=1;
	for (auto v:e[u]) if (v!=fa){
		dfs(v,u);
		For(j,0,max(mx[u],mx[v]+1)) tmp[j]=0;
		For(j,0,mx[u]) tmp[j]=1ll*f[u][j]*g[v]%mod;
		For(j,0,mx[u]){
			For(l,0,min(mx[v],k-j-1)) tmp[max(j,l+1)]=(tmp[max(j,l+1)]+1ll*f[u][j]*f[v][l])%mod;
		}
		mx[u]=max(mx[u],mx[v]+1);
		For(j,0,mx[u]) f[u][j]=tmp[j];
	}
	For(i,0,k) upd(g[u],f[u][i]);
}

int main(){
	n=read(),k=read();
	FOR(i,1,n){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0),printf("%d\n",g[1]);
}