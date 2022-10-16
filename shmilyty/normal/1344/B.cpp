#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int Maxn=1010,inf=0x3f3f3f3f;
const int dx[]={1,-1,0,0},dy[]={0,0,-1,1};
bool vis[Maxn][Maxn],a[Maxn][Maxn];
bool r[Maxn],c[Maxn],flag[Maxn][2];
int n,m,ans;
inline bool check(int x,int y)
{
	return (x<1 || y<1 || x>n || y>m || vis[x][y] || !a[x][y]);
}
void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<4;++i)
	{
		int u=x+dx[i],v=y+dy[i];
		if(check(u,v))continue;
		dfs(u,v);
	}
}
int main()
{
//	freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		char s[Maxn];
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
		if(s[j]=='#')
		{
			a[i][j]=1;
			r[i]=c[j]=1;
		}
	}
	for(int i=1;i<=n;++i)
	{
		int pos=0;
		for(int j=1;j<=m;++j)
		if(a[i][j]){pos=j;break;}
		if(!pos)continue;
		for(int j=pos+2;j<=m;++j)
		if(a[i][j] && !a[i][j-1])
		{puts("-1");return 0;}
	}
	for(int j=1;j<=m;++j)
	{
		int pos=0;
		for(int i=1;i<=n;++i)
		if(a[i][j]){pos=i;break;}
		if(!pos)continue;
		for(int i=pos+2;i<=n;++i)
		if(a[i][j] && !a[i-1][j])
		{puts("-1");return 0;}
	}
	
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	if(a[i][j] || (!r[i] && !c[j]))
	flag[i][0]=flag[j][1]=1;
	for(int i=1;i<=n;++i)
	if(!flag[i][0]){puts("-1");return 0;}
	for(int i=1;i<=m;++i)
	if(!flag[i][1]){puts("-1");return 0;}
	
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	{
		if(vis[i][j] || !a[i][j])continue;
		dfs(i,j),++ans;
	}
	printf("%d\n",ans);
	return 0;
}