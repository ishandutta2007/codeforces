#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define mid ((l+r)>>1)

using namespace std;
typedef long long LL;
const int N=505;
const LL INF=10000000000000000;
int n,m;
LL dis[N][N],f[N][N],ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x;
}

void solve()
{
	n=getint(),m=getint();
	rep(i,1,n) rep(j,1,n) dis[i][j]=INF;
	rep(i,1,m)
	{
		int u=getint(),v=getint();
		LL w=getint();
		dis[u][v]=min(dis[u][v],w);
		dis[v][u]=min(dis[v][u],w);
	}
	rep(i,1,n) f[i][1]=dis[1][i];
	rep(i,2,n-1)
		rep(j,1,n)
		{
			f[j][i]=INF;
			rep(k,1,n)
				if(dis[j][k]<INF && f[k][i-1]<INF)
					f[j][i]=min(f[j][i],min(f[k][i-1],dis[j][k]));
		}		
	ans=INF;
	rep(i,1,n-1) if(f[n][i]<INF) ans=min(ans,f[n][i]*i);
	rep(i,1,n) rep(j,1,n)
		if(dis[i][j]<INF) f[i][j]=1;
		else f[i][j]=INF;
	rep(i,1,n) f[i][i]=0;
	rep(k,1,n) rep(i,1,n) rep(j,1,n)
		f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	rep(i,1,n) rep(j,1,n) if(dis[i][j]<INF)
		rep(k,1,n) ans=min(ans,dis[i][j]*(f[i][k]+f[1][k]+f[k][n]+2));
	printf("%lld\n",ans);
}

int main()
{
	int T=getint();
	while(T--) solve();
	return 0;
}