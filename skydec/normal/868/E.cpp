#include<bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
const int N=55;
int head[N],np[N<<1],p[N<<1],w[N<<1],tot;
int dis[N][N];
int at[N];
int ss;
int n,m;
int f[N][N][N][N];
bool suan[N][N][N][N];
int du[N];
int dp(int u,int v,int out,int in){
	if(out==0&&in==0)return 0;
	if(suan[u][v][out][in])return f[u][v][out][in];

	if(du[v]==1){
		if(out==0)return 0;
		suan[u][v][out][in]=1;
		return f[u][v][out][in]=dp(v,u,0,out)+dis[v][u];
	}

	int g[N];
	rep(i,0,in)g[i]=-(1e9);
	g[0]=1e9;
	for(int xx=head[v];xx;xx=np[xx])if(p[xx]!=u){
		int y=p[xx];

		per(i,in,1)rep(j,1,i)g[i]=max(g[i],min(g[i-j],dp(v,y,out+in-j,j)+dis[v][y]));
	}

	suan[u][v][out][in]=1;
	return f[u][v][out][in]=g[in];
}
int dfs(int x,int ff){
	int ans=at[x];
	for(int u=head[x];u;u=np[u])
	if(p[u]^ff)
		ans+=dfs(p[u],x);
	return ans;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		++tot;p[tot]=b;np[tot]=head[a];head[a]=tot;w[tot]=c;
		++tot;p[tot]=a;np[tot]=head[b];head[b]=tot;w[tot]=c;
		dis[a][b]=dis[b][a]=c;
		du[a]++;du[b]++;
	}
	scanf("%d",&ss);
	scanf("%d",&m);
	rep(i,1,m){
		int x;scanf("%d",&x);at[x]++;
	}
	int ans=1<<30;
	for(int u=head[ss];u;u=np[u]){
		int num=dfs(p[u],ss);
		if(num)ans=min(ans,dp(ss,p[u],m-num,num)+w[u]);
	}
	printf("%d\n",ans);
	return 0;
}