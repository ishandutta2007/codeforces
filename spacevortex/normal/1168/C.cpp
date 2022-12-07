#include<bits/stdc++.h>
#define cmin(a,b) a=min(a,b)
using namespace std;
const int N=3e5+50,S=25;
int n,Q;
int a[N],f[N][S],g[S];
int main()
{
	int i,j,k,x,y,pd;
	scanf("%d%d",&n,&Q);
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=n;i>=1;i--)
	{
		for(j=0;j<20;j++)
		{
			for(k=0;k<20;k++)
			{
				if((a[i]&(1<<k))&&g[k]<=n)
				{
					cmin(f[i][j],f[g[k]][j]);
				}
			}
		}
		for(j=0;j<20;j++)
		{
			if(a[i]&(1<<j)) f[i][j]=g[j]=i;
		}
		//for(j=0;j<20;j++) printf("#%d %d %d\n",i,j,f[i][j]);
	}
	while(Q--)
	{
		pd=0;
		scanf("%d%d",&x,&y);
		for(i=0;i<20;i++)
		{
			if((a[y]&(1<<i))&&f[x][i]<=y) pd=1;
		}
		if(pd) puts("Shi");
		else puts("Fou");
	}
	return 0;
}