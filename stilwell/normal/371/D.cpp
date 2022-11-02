#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,opt;
int fa[300005];
long long lim[300005],p[300005],x;

int get(int p)
{
	if(fa[p]==p)return p;
	fa[p]=get(fa[p]);
	return fa[p];
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%I64d",&lim[i]);
	scanf("%d",&m);
	for(i=1;i<=n+1;++i)fa[i]=i;
	for(;m;--m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%I64d",&k,&x);
			for(k=get(k);k<=n&&x>0;k=get(k))
			{
				if(lim[k]-p[k]<=x)
				{
					x-=lim[k]-p[k];
					p[k]=lim[k];
					fa[k]=k+1;
				}
				else
				{
					p[k]+=x;
					x=0;
				}
			}
		}
		else
		{
			scanf("%d",&k);
			printf("%I64d\n",p[k]);
		}
	}
}