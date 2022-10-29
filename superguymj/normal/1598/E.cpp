#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=1005;
bool vis[N][N];
int n,m,f[N][N][2],q,tot;
LL ans;

int getint()
{
	char ch;
	while(!isdigit(ch=getchar()));
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;	
	return x;
}

void dfs(int x,int y,int t)
{
	if(!x || !y) return;
	if(vis[x][y]) return;
	ans-=f[x][y][0]+f[x][y][1];
	f[x][y][t]=1;
	if(t==0)
	{
		if(x+1<=n) f[x][y][t]=f[x+1][y][t^1]+1;
		dfs(x,y-1,1);
	}
	else
	{
		if(y+1<=m) f[x][y][t]=f[x][y+1][t^1]+1;
		dfs(x-1,y,0);
	}
	ans+=f[x][y][0]+f[x][y][1];
}

void solve()
{
	n=getint(),m=getint(),q=getint(),tot=ans=0;
	repd(i,n,1) repd(j,m,1)
	{
		f[i][j][0]=f[i][j][1]=1;
		if(i+1<=n) f[i][j][0]=f[i+1][j][1]+1;
		if(j+1<=m) f[i][j][1]=f[i][j+1][0]+1;
		ans+=f[i][j][0]+f[i][j][1],++tot;
		vis[i][j]=0;
	}
	while(q--)
	{
		int i=getint(),j=getint();
		if(vis[i][j]==0)
		{
			vis[i][j]=1,--tot,ans-=f[i][j][0]+f[i][j][1];
			f[i][j][0]=f[i][j][1]=0;
			dfs(i-1,j,0),dfs(i,j-1,1);
		}
		else
		{
			vis[i][j]=0,++tot;
			f[i][j][0]=f[i][j][1]=1;
			if(i+1<=n) f[i][j][0]=f[i+1][j][1]+1;
			if(j+1<=m) f[i][j][1]=f[i][j+1][0]+1;
			ans+=f[i][j][0]+f[i][j][1];
			dfs(i-1,j,0),dfs(i,j-1,1);
		}
		printf("%lld\n",ans-tot);
	}
}

int main()
{
	solve();
	return 0;
}