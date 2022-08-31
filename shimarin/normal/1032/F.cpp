#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) cerr<<i<<" ";puts("")
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

const int N = 3e5+10;
int n;
poly e[N];

const int mod = 998244353;
inline int power(int a,int b){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%mod) if (b&1) ret=1ll*ret*a%mod;
	return ret;
}

int f[N][3];
inline void dfs(int u,int fa){
	f[u][1]=f[u][2]=1;
	int s=1;
	for (auto v:e[u]) if (v!=fa){
		dfs(v,u);
		f[u][1]=1ll*f[u][1]*(f[v][0]+f[v][1])%mod;
		s=1ll*s*(f[v][1]+2ll*f[v][0])%mod;
		f[u][2]=1ll*f[u][2]*(f[v][1]+2ll*f[v][0])%mod;
	}
	for (auto v:e[u]) if (v!=fa){
		int x=1ll*s*power((2ll*f[v][0]+f[v][1])%mod,mod-2)%mod;
		f[u][0]=(f[u][0]+1ll*x*f[v][2])%mod;
	}
}

int main(){
	n=read();
	FOR(i,1,n){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0),printf("%d\n",(f[1][0]+f[1][1])%mod);
}