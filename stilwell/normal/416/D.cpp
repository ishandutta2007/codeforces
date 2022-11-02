#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,ans;
long long a[200005],d;

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%I64d",&a[i]);
	for(k=1;k<=n;)
	{
		++ans;
		for(i=k;a[i]==-1;++i);
		for(j=i+1;a[j]==-1;++j);
		if(j>n)break;
		if((a[j]-a[i])%(j-i)!=0){k=j;continue;}
		d=(a[j]-a[i])/(j-i);
		if(a[j]-d*(j-k)<=0){k=j;continue;}
		for(k=j+1;k<=n&&a[j]+d*(k-j)>0&&(a[k]==-1||a[k]==a[j]+d*(k-j));++k);
	}
	printf("%d\n",ans);
}