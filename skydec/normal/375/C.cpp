#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define per(i,j,k) for(int i=j;i>=k;i--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int dis[23][23][256];
int tw[10];
struct jsb
{
	int i,j,zt;
	inline void mk(int a,int b,int s)
	{
		i=a;j=b;zt=s;
	}
}q[210000];int top=0;int boom[9];int tt=0;
int n,m;int go[23][23];int c=8;int sx,sy;
int check(int x)
{
	rep(i,tt+1,8)if(x&tw[i-1])return -1;
	int res=0;rep(i,1,tt)if(x&tw[i-1])res+=boom[i];
	return res;
}
int main()
{
	scanf("%d%d",&n,&m);tw[0]=1;rep(i,1,8)tw[i]=tw[i-1]*2;
	rep(i,1,n)rep(j,1,m)
	{
		char p=getchar();
		while(p==' '||p=='\n'||p=='\t')p=getchar();
		if(p=='.')go[i][j]=0;
		else if('1'<=p&&p<='9'){go[i][j]=p-'0';if(go[i][j]>tt)tt=go[i][j];}
		else if(p=='S'){sx=i;sy=j;}
		else if(p=='B'){go[i][j]=c--;}
		else go[i][j]=-1;
	}
	//int zt=0;rep(i,1,sx-1)if(go[i][sy])zt^=tw[go[i][sy]-1];
	dis[sx][sy][0]=1;q[top=1].mk(sx,sy,0);
	for(int pq=1;pq<=top;pq++)
	{
		int x,y,zt;x=q[pq].i;y=q[pq].j;zt=q[pq].zt;
		if(x+1<=n&&go[x+1][y]==0&&dis[x+1][y][zt]==0)
		{
			dis[x+1][y][zt]=dis[x][y][zt]+1;
			q[++top].mk(x+1,y,zt);
		}
		if(x-1>=1&&go[x-1][y]==0&&dis[x-1][y][zt]==0)
		{
			dis[x-1][y][zt]=dis[x][y][zt]+1;
			q[++top].mk(x-1,y,zt);
		}
		if(y+1<=m&&go[x][y+1]==0)
		{
			int u=zt;
			rep(i,1,x-1)
			if(go[i][y+1]>0)u^=tw[go[i][y+1]-1];
			if(dis[x][y+1][u]==0)
			{
				dis[x][y+1][u]=dis[x][y][zt]+1;
				q[++top].mk(x,y+1,u);
			}
		}
		if(y-1>=1&&go[x][y-1]==0)
		{
			int u=zt;
			rep(i,1,x-1)
			if(go[i][y]>0)u^=tw[go[i][y]-1];
			if(dis[x][y-1][u]==0)
			{
				dis[x][y-1][u]=dis[x][y][zt]+1;
				q[++top].mk(x,y-1,u);
			}
		}
	}
	rep(i,1,tt)scanf("%d",&boom[i]);
	int ans=0;
	//rep(i,1,n)rep(j,1,m)rep(st,0,255)if(dis[i][j][st])printf("%d %d %d %d\n",i,j,st,dis[i][j][st]);
	rep(i,0,255)if(dis[sx][sy][i])
	{
		int value=check(i);
		ans=max(ans,value-(dis[sx][sy][i]-1));
	}
	printf("%d\n",ans);
	return 0;
}