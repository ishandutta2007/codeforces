#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp pake_pair
#define x0 fuckcjb
#define y0 fuckyzc
#define x1 fucksm
#define y1 fucklzw
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=2e5+5,MOD=1e9+7;
const ld eps=1e-12;
int n;
vector<int>g[N];
ll s[2][N],siz[2][N];
void dfs(int x,int fa){
	for(auto v:g[x])if(v!=fa){
		dfs(v,x);
		siz[0][x]+=siz[1][v],siz[1][x]+=siz[0][v];
		s[0][x]+=s[1][v],s[1][x]+=s[0][v];
	}
	s[0][x]+=siz[0][x],s[1][x]+=siz[1][x];
	++siz[0][x];
	//printf("%lld %lld %lld %lld\n",s[0][x],s[1][x],siz[0][x],siz[1][x]);
}
void dfs2(int x,int fa){
	for(auto v:g[x])if(v!=fa){
		ll n1,n0;
		n1=s[1][v]+s[0][x]-s[1][v]-siz[1][v]+siz[0][x]-siz[1][v];
		n0=s[0][v]+s[1][x]-s[0][v]-siz[0][v]+siz[1][x]-siz[0][v];
		s[1][v]=n1,s[0][v]=n0;
		siz[1][v]+=siz[0][x]-siz[1][v];
		siz[0][v]+=siz[1][x]-siz[0][v];
		dfs2(v,x);
	}
}
int main(){
	scanf("%d",&n);
	rep(i,n-1){
		int x,y;scanf("%d%d",&x,&y);
		g[x].pb(y),g[y].pb(x);
	}
	dfs(1,0);
	dfs2(1,0);
	//rep(x,n)
	//	printf("%lld %lld %lld %lld\n",s[0][x],s[1][x],siz[0][x],siz[1][x]);
	ll ans=0;
	rep(i,n)ans+=s[0][i]/2+(s[1][i]+siz[1][i])/2;
	printf("%lld\n",ans/2);
	return 0;
}