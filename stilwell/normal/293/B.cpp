#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int n,m,q,K,i,j,k;
int C[15][15],a[15][15],b[15][15],c[15],fac[15],ans;
bool use[15];

void dfs(int x,int y,int z)
{
	if(y>m)++x,y=1;
	if(x>n)
	{
		ans=(ans+1ll*C[K-q][z-q]*fac[z-q]%p)%p;
		return;
	}
	int i;
	b[x][y]=b[x-1][y]|b[x][y-1];
	if(a[x][y])
	{
		if(c[a[x][y]])
		{
			if(b[x][y]&(1<<c[a[x][y]]))return;
			b[x][y]+=1<<c[a[x][y]];
			dfs(x,y+1,z);
		}
		else
		{
			for(i=1;i<=z;++i)
			if(!use[i]&&((b[x][y]&(1<<i))==0))
			{
				use[i]=true;c[a[x][y]]=i;
				b[x][y]+=1<<i;
				dfs(x,y+1,z);
				b[x][y]-=1<<i;
				use[i]=false;c[a[x][y]]=0;
			}
			if(z==K)return;
			c[a[x][y]]=++z;b[x][y]+=1<<z;use[z]=true;
			dfs(x,y+1,z);
			c[a[x][y]]=0;use[z]=false;
		}
	}
	else
	{
		for(i=1;i<=z;++i)
		if((b[x][y]&(1<<i))==0)
		{
			b[x][y]+=1<<i;
			dfs(x,y+1,z);
			b[x][y]-=1<<i;
		}
		if(z==K)return;
		++z;b[x][y]+=1<<z;
		dfs(x,y+1,z);
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&K);
	if(n+m-1>K){printf("0\n");return 0;}
	C[0][0]=1;
	for(i=0;i<=K;++i)
	for(j=0;j<=i;++j)
	{
		if(C[i][j]>=p)C[i][j]-=p;
		C[i+1][j]+=C[i][j];
		C[i+1][j+1]+=C[i][j];
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		scanf("%d",&a[i][j]);
		if(a[i][j]&&!use[a[i][j]])
		{
			use[a[i][j]]=true;
			++q;
		}
	}
	fac[0]=1;
	for(i=1;i<=K;++i)fac[i]=1ll*fac[i-1]*i%p;
	for(i=1;i<=K;++i)use[i]=false;
	dfs(1,1,0);
	printf("%d\n",ans);
}