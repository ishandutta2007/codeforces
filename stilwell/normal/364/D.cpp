#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,i,j,k,shi__,tot,sum[1000005],l,r,mid,aim;
long long a[1000005],d[1000005],ans,x,y;

long long gcd(long long a,long long b){if(!b)return a;return gcd(b,a%b);}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%I64d",&a[i]);
	for(shi__=1;shi__<=10;++shi__)
	{
		x=a[((rand()<<15)+rand())%n+1];tot=0;
		for(i=1;(long long)i*i<=x;++i)
		if(x%i==0)
		{
			d[++tot]=i;
			if((long long)i*i!=x)d[++tot]=x/i;
		}
		sort(d+1,d+tot+1);
		for(i=1;i<=tot;++i)sum[i]=0;
		for(i=1;i<=n;++i)
		{
			y=gcd(a[i],x);
			l=1;r=tot;aim=tot+1;
			while(l<=r)
			{
				mid=l+r>>1;
				if(d[mid]<=y)aim=mid,l=mid+1;
				else r=mid-1;
			}
			++sum[aim];
		}
		for(i=1;i<=tot;++i)
		for(j=1;j<i;++j)
		if(d[i]%d[j]==0)
		sum[j]+=sum[i];
		for(i=1;i<=tot;++i)
		if(d[i]>ans&&sum[i]*2>=n)
		ans=d[i];
	}
	printf("%I64d\n",ans);
}