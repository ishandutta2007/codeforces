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
int n,l[N],r[N];
poly e[N];

ll f[N][2];
inline void dfs(int u,int fa){
	f[u][0]=f[u][1]=0;
	for (auto v:e[u])if (v!=fa){
		dfs(v,u);
		f[u][0]=max(f[u][0]+f[v][0]+abs(l[u]-l[v]),f[u][0]+f[v][1]+abs(l[u]-r[v]));
		f[u][1]=max(f[u][1]+f[v][0]+abs(r[u]-l[v]),f[u][1]+f[v][1]+abs(r[u]-r[v]));
	}
}
inline void solve(){
	n=read();
	For(i,1,n) l[i]=read(),r[i]=read(),e[i].clear();
	FOR(i,1,n){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0);
	printf("%lld\n",max(f[1][0],f[1][1]));
}

int main(){
	int T=read();
	while (T--) solve();
}