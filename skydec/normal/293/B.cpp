#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#define Rep(i,j,k) for(int i=j;i<=k;i++)
#define lowbit(x) ((x)&(-(x)))
#define jsb 1000000007
#define max(x,y) (((x)>(y))?(x):(y))
using namespace std;
int A[22][22];int n,m,k;
int a[22][22];int wei[50];int wt=0;
#define log2 LL2g
int Use[22][22];int YL[22][22];int log2[1000000];
long long ans=0;
void dfs(int x,int y,int up)
{
	if(x>n)
	{
		ans=ans+A[k-wt][up-wt];
		return;
	}
	if(a[x][y])
	{
		YL[x][y]=(YL[x-1][y]|YL[x][y-1]);
		if(YL[x][y]&(1<<(a[x][y]-1)))return;
		YL[x][y]|=(1<<(a[x][y]-1));
		if(y==m)dfs(x+1,1,up);else dfs(x,y+1,up);
	}
	else
	{
		int X=YL[x-1][y]|YL[x][y-1];
		for(int s=(~X)&((1<<k)-1);s;s-=lowbit(s))
		{
			int i=log2[lowbit(s)];if(i>up+1)break;
			int P=X;
			if(P&(1<<i-1))continue;
			if(Use[x][y]&(1<<i-1))continue;
			P|=(1<<i-1);
			YL[x][y]=P;
			if(y==m)dfs(x+1,1,max(i,up));else dfs(x,y+1,max(i,up));
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	if(n+m-1>k){printf("0\n");return 0;}
	Rep(i,0,20){A[i][0]=1;Rep(j,1,i+1)A[i][j]=A[i][j-1]*1ll*(i+1-j)%jsb;}
	Rep(i,1,20)log2[1<<(i-1)]=i;
	Rep(i,1,n)Rep(j,1,m)
	{
		scanf("%d",&a[i][j]);
		if(a[i][j])
		{
			if(!wei[a[i][j]])wei[a[i][j]]=++wt;
			a[i][j]=wei[a[i][j]];
		}
		Use[i][j]=(Use[i-1][j]|Use[i][j-1]);
		if(a[i][j])
		if(Use[i][j]&(1<<a[i][j]-1))
		{
			printf("0\n");
			return 0;
		}
		if(a[i][j])
		Use[i][j]|=(1<<a[i][j]-1);
		}
	dfs(1,1,wt);
	printf("%I64d\n",ans%jsb);
	return 0;
}