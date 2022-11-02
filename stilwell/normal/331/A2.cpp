#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;

int n,i,j,k,ll,rr,tot;
int a[300005],c[300005];
long long ans,tmp,sum[300005];

map <int,int> l;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	ans=-1000000000000000ll;
	for(i=1;i<=n;++i)
	{
		if(a[i]>0)sum[i]=sum[i-1]+a[i];
		else sum[i]=sum[i-1];
		if(l[a[i]])
		{
			tmp=sum[i-1]-sum[l[a[i]]];
			tmp+=a[i]*2;
			if(tmp>ans)ans=tmp,ll=l[a[i]],rr=i;
		}else l[a[i]]=i;
	}
	for(i=1;i<ll;++i)c[++tot]=i;
	for(i=ll+1;i<rr;++i)if(a[i]<0)c[++tot]=i;
	for(i=rr+1;i<=n;++i)c[++tot]=i;
	printf("%I64d %d\n",ans,tot);
	for(i=1;i<=tot;++i)printf("%d ",c[i]);
	printf("\n");
}