#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int n,m;
char str1[35],str2[35];
bool reach[35][35];
void dfs(int x,int y)
{
	if(reach[x][y])return;
	//printf("%d %d %c %c\n",x,y,str1[x],str2[y]);
	reach[x][y]=1;
	if(str1[x]=='<')
	{
		if(y-1>0)
		dfs(x,y-1);
	}
	else
	{
		if(y+1<=m)
		dfs(x,y+1);
	}
	
	if(str2[y]=='^')
	{
		if(x-1>0)
		dfs(x-1,y);
	}
	else 
	if(x+1<=n)
	dfs(x+1,y);
}
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",str1+1);
	scanf("%s",str2+1);bool f=1;
	//printf("%s\n",str1+1);
	//printf("%s\n",str2+1);
	rep(i,1,n)
	rep(j,1,m)
	{
		//printf("%d %d %d\n",i,j,f);
		memset(reach,0,sizeof reach);
		dfs(i,j);
		rep(x,1,n)rep(y,1,m)f&=reach[x][y];
		if(!f)break;
	}
	if(f)printf("YES\n");else printf("NO\n");
}