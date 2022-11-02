#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,i,j,k,len,tot,w,u,v;
long long a[1000005],b[1000005],c[1000005],pre[1000005];
bool use[1000005];

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%lld",&b[i]);
	for(w=60;w>=0;--w)
	{
		tot=0;
		for(i=1;i<=n;++i)if(!use[i]&&(b[i]&(1ll<<w)))c[++tot]=b[i],use[i]=true;
		u=0;
		for(i=1;i<=len;++i)
		{
			pre[i]=a[i];
			if(a[i]&(1ll<<w))++u;
		}
		if(tot>u+1)
		{
			printf("No\n");
			return 0;
		}
		if(!tot)continue;
		
		k=v=0;
		a[++v]=c[++k];
		for(i=1;i<=len;++i)
		{
			a[++v]=pre[i];
			if((pre[i]&(1ll<<w))&&(k<tot))a[++v]=c[++k];
		}
		len=v;
	}
	printf("Yes\n");
	for(i=1;i<=n;++i)printf("%I64d ",a[i]);
	printf("\n");
	
	return 0;
	for(i=1;i<=n;++i)a[i]^=a[i-1],printf("%I64d ",a[i]);
	
}