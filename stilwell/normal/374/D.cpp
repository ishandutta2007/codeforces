#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,l,tot,K;
int a[1000005],hit[1000005],opt[1000005];
int sum[5000005];
bool empty;

int main()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	l=1;while(l<m)l*=2;
	for(i=1;i<=m;++i)
	{
		scanf("%d",&opt[i]);
		if(opt[i]==-1)
		{
			for(j=1;j<=n;++j)
			{
				if(a[j]>tot)break;
				K=a[j];
				for(k=1;k<l;)
				{
					if(sum[k*2]>=K)k*=2;
					else K-=sum[k*2],k=k*2+1;
				}
				hit[j]=k;
			}
			tot-=j-1;
			for(--j;j;--j)
			{
				for(k=hit[j];k;k/=2)
				--sum[k];
			}
		}
		else
		{
			for(j=l+i-1;j;j/=2)++sum[j];
			++tot;
		}
	}
	empty=true;
	for(i=1;i<=m;++i)
	if(sum[l+i-1])
	{
		printf("%d",opt[i]);
		empty=false;
	}
	if(empty)printf("Poor stack!");
	printf("\n");
}