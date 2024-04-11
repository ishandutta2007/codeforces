#include<bits/stdc++.h>
#define cmin(a,b) a=min(a,b)
#define cmax(a,b) a=max(a,b)
#define cle(a,b) memset(a,0,sizeof(int)*(b))
using namespace std;
const int N=2e5+50,inf=1e9;
int T,n;
char s[N];
int w[N],L[20],R[20],col[N],dp[N][10][10],val[N][10][10];
int Solve()
{
	int W,i,j,x,k,las=-inf,a=-1,b=-1;
	scanf("%d",&n);
	scanf("%s",s+1);
	memset(L,0x3f,sizeof(L));
	memset(R,-0x3f,sizeof(R));
	for(i=1;i<=n;i++)
	{
		w[i]=s[i]-'0';
		cmin(L[w[i]],i);cmax(R[w[i]],i);
	}
	cle(col,n+5);
	for(W=0;W<10;W++)
	{
		for(i=0;i<=n;i++)
		for(j=0;j<10;j++)
		for(k=0;k<10;k++)
		dp[i][j][k]=0;
		dp[0][0][W]=1;
		for(i=0;i<n;i++)
		{
			x=w[i+1];
			for(j=0;j<=W;j++)
			{
				for(k=W;k<10;k++)
				{
					if(!dp[i][j][k]) continue;
					if(j<=x) dp[i+1][x][k]=1,val[i+1][x][k]=1;
					if(k<=x) dp[i+1][j][x]=1,val[i+1][j][x]=2;
				}
			}
		}
		for(i=0;i<=W;i++)
		{
			for(j=W;j<10;j++)
			{
				if(dp[n][i][j]) a=i,b=j;
			}
		}
		if(a!=-1) break;
	}
	if(a==-1) return -1;
	x=n;
	while(x>0)
	{
		col[x]=val[x][a][b];
		if(col[x]==1) 
		{
			for(i=0;i<=a;i++)
			{
				if(dp[x-1][i][b]) 
				{
					a=i;break;
				}
			}
		}
		else
		{
			for(i=W;i<b;i++)
			{
				if(dp[x-1][a][i]) 
				{
					b=i;break;
				}
			}
		}
		x--;
	}
	for(i=1;i<=n;i++)
	{
		if(col[i]) continue;
		col[i]=2;if(w[i]<las) return -1;
		las=w[i];
	}
	for(i=1;i<=n;i++) putchar(col[i]+'0');
	putchar('\n');
	return 1;
}
int main()
{
	scanf("%d",&T);
	while(T--) 
	{
		if(Solve()==-1) puts("-");
	}
	return 0;
}