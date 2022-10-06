#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 102000 ,mo=1e9+7;const ll MO = 7LL*mo*mo;
Vi e[N];int n,k,f[N][202],g[N][202],ans[205],C[N][202],sz[N];
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void dfs(int u, int fa){
	sz[u]=1;f[u][0]=1;
	rep(i,0,SZ(e[u])-1)if(e[u][i]!=fa){
		int v=e[u][i];dfs(e[u][i],u);ll g[202]={0};
		rep(a,0,k)if(f[v][a])per(b,min(k-a,sz[u]),0)if(f[u][b])
			{g[a+b]=(g[a+b]+1LL*f[v][a]*f[u][b]);g[a+b]=g[a+b]<MO?g[a+b]:g[a+b]-MO;}
		rep(a,0,k)f[u][a]=g[a]%mo;sz[u]+=sz[v];
	}
	rep(i,0,k)if(f[u][i]){
		if(u>1)add(g[n-sz[u]-1][i],f[u][i]);//rep(j,i+1,k)ans[j]=(ans[j]+2LL*f[u][i]*C[n-sz[u]-1][j-i-1])%mo;//
		else add(ans[i],2LL*f[u][i]%mo);
	}
	rep(i,0,k)f[u][i]=(2LL*f[u][i]+(i-1>=0?C[sz[u]-1][i-1]:0))%mo;
}
inline void init(){
	ll tmp[205]={0};
	rep(i,0,n)rep(j,0,k)if(g[i][j])rep(c,j+1,k){
		tmp[c]+=1LL*g[i][j]*C[i][c-j-1];tmp[c]=tmp[c]<MO?tmp[c]:tmp[c]-MO;
	}
	rep(i,0,k)ans[i]=(ans[i]+tmp[i]%mo*2LL)%mo;
}
ll solve(int c){
	static int dp[205][205];
	memset(dp,0,sizeof(dp));dp[0][c]=1;//1..k
	rep(i,0,k-1)rep(j,0,k)if(dp[i][j]){
		if(j-1>=0)add(dp[i+1][j-1],1LL*dp[i][j]*j%mo);
		add(dp[i+1][j],1LL*dp[i][j]*(n-1-j)%mo);
	}
	return dp[k][0];
}
int main() {
	read(n);read(k);rep(i,1,n-1){int u,v;read(u);read(v);e[u].pb(v);e[v].pb(u);}
	rep(i,0,n){
		C[i][0]=1;rep(j,1,k)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
		if(i<=k)C[i][i]=1;
	}
	dfs(1,0);ll res=0;//1LL*(power(2,n)-1)*power(n-1,k)%mo;
	init();
	rep(i,0,k)ans[i]=(ans[i]-1LL*i*C[n-1][i]+1LL*mo*mo)%mo;
	rep(i,0,k)res=(res+1LL*(i&1?-1:1)*ans[i]*solve(i))%mo;
	//rep(i,0,k)printf("%d:%d %lld\n",i,ans[i],solve(i));
	cout<<(res%mo+mo)%mo;
	return 0;
}