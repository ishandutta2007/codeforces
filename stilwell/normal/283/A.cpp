#include <stdio.h>
#include <stdlib.h>
using namespace std;

int m,n,l,i,j,k,opt,x,y;
long long sum[400005],a[400005],ans;

int main()
{
	scanf("%d",&n);
	l=1;
	for(m=1;m<=n;++m)
	{
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&x,&y);
			ans+=(long long)x*y;
			for(i=x;i;i-=i&-i)sum[i]+=y;
		}
		if(opt==2)
		{
			scanf("%d",&x);
			a[++l]=x;
			for(i=l;i<=n;i+=i&-i)a[l]-=sum[i];
			ans+=x;
		}
		if(opt==3)
		{
			for(i=l;i<=n;i+=i&-i)ans-=sum[i];
			ans-=a[l--];
		}
		printf("%.6lf\n",1.0*ans/l);
	}
}