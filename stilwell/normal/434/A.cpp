#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,tot,mid;
int a[100005],b[1000005];
int son[100005],next[1000005],num[1000005];
long long ans,Min,sum1,sum2;

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d",&a[i]);
	for(i=1;i<m;++i)
	if(a[i]!=a[i+1])
	{
		++tot;num[tot]=a[i];next[tot]=son[a[i+1]];son[a[i+1]]=tot;
		++tot;num[tot]=a[i+1];next[tot]=son[a[i]];son[a[i]]=tot;
		if(a[i]>a[i+1])ans+=a[i]-a[i+1];else ans+=a[i+1]-a[i];
	}
	for(i=1;i<=n;++i)
	if(son[i])
	{
		tot=0;sum1=sum2=0;
		for(j=son[i];j;j=next[j])b[++tot]=num[j];
		sort(b+1,b+tot+1);
		mid=b[tot/2+tot%2];
		for(j=1;j<=tot;++j)
		{
			if(b[j]>i)sum1+=b[j]-i;else sum1+=i-b[j];
			if(b[j]>mid)sum2+=b[j]-mid;else sum2+=mid-b[j];
		}
		if(sum2-sum1<Min)Min=sum2-sum1;
	}
	printf("%I64d\n",ans+Min);
}