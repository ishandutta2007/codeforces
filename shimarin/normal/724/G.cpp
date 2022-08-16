#include<bits/stdc++.h>
#define For(i,x,y) for (int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (int i=(x);i<(y);i++)
#define Dow(i,x,y) for (int i=(x);i>=(y);i--)
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

const int N = 1e5+10, mod = 1e9+7;
int n,m,ans,pw[510];
vector<PA>e[N];

ll all;
int siz;
struct Basi{
	ll v[65];
	void init(){
		fil(v,0);
	}
	bool ins(ll x){
		Dow(i,60,0) if (x>>i&1){
			if (!v[i]){
				v[i]=x;
				return 1;
			}
			x^=v[i];
		}
		return 0;
	}
}xxj;

int fa[N],c;
bool vis[N];
ll f[N];
poly vec;
inline void dfs(int u){
	vis[u]=1,vec.pb(u);
	for (auto [v,w]:e[u]) if (v!=fa[u]){
		if (!vis[v]){
			fa[v]=u,f[v]=f[u]^w,dfs(v);
		} else {
			if (xxj.ins(f[u]^f[v]^w)) ++siz;
		}
	}
}

int main(){
	n=read(),m=read();
	For(i,1,m){
		ll x=read(),y=read(),z=read();
		e[x].ep(y,z),e[y].ep(x,z);
	}
	pw[0]=1;
	For(i,1,60) pw[i]=1ll*pw[i-1]*2%mod;
	For(i,1,n) if (!vis[i]){
		vec.clear(),xxj.init(),siz=0,dfs(i);
		all=0;
		For(j,0,60) all|=xxj.v[j];
		For(j,0,60){
			poly cnt={0,0};
			for (auto u:vec){
				cnt[f[u]>>j&1]++;
			}
			if (all>>j&1){
				int t=(1ll*cnt[0]*cnt[1]+1ll*cnt[0]*(cnt[0]-1)/2+1ll*cnt[1]*(cnt[1]-1)/2)%mod;
				ans=(ans+1ll*t*pw[j]%mod*pw[siz-1])%mod;
			} else {
				ans=(ans+1ll*cnt[0]*cnt[1]%mod*pw[j]%mod*pw[siz])%mod;
			}
		}
	}
	printf("%d\n",ans);
}