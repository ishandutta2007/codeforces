#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k;
char s[25];
int f[45][1200005],S[45][45];
bool g[45][1200005];

void dfs(int x,int y)
{
	int i,j,k;
	if(g[x][y])return;
	g[x][y]=true;
	if(x&1)f[x][y]=1000000000;
	else f[x][y]=-1000000000;
	if(x==2*n-1)f[x][y]=0;
	for(i=1;i<=26;++i)
	{
		k=0;
		for(j=1;j<=n;++j)
		if(y&(1<<j-1))
		{
			if(S[x+1][j]==i)k|=1<<j-1;
			if(S[x+1][j+1]==i)k|=1<<j;
		}
		if(k)
		{
			dfs(x+1,k);
			if(x&1)
			{
				if(f[x+1][k]<f[x][y])f[x][y]=f[x+1][k];
			}
			else
			{
				if(f[x+1][k]>f[x][y])f[x][y]=f[x+1][k];
			}
		}
	}
	for(i=1;i<=n;++i)
	if(y&(1<<i-1))break;
	if(S[x][i]==1)++f[x][y];
	if(S[x][i]==2)--f[x][y];
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(j=1;j<=n;++j)
		S[i+j-1][j]=s[j]-'a'+1;
	}
	dfs(1,1);
	if(f[1][1]>0)printf("FIRST\n");
	if(f[1][1]==0)printf("DRAW\n");
	if(f[1][1]<0)printf("SECOND\n");
}