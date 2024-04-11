#include<cstdio>

using namespace std;

long long L,A,B,n,l,t,m,r,ans,mid;

int check(long long now)
{
	if(now==L)return 1ll*(A+1ll*(now-1)*B)<=t;
	return (A+(now-1)*B<=t)&&((A+(L-1)*B+A+(now-1)*B)*(now-L+1)/2<=t*m);
}

int main()
{
	scanf("%I64d%I64d%I64d",&A,&B,&n);
	for(int i=1;i<=n;i++)
	{
		ans=-1;
		scanf("%I64d%I64d%I64d",&L,&t,&m);
		l=L;
		r=1000000;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(mid>170000)
				mid=(l+r)>>	1;
			if(check(mid))ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%I64d\n",ans);
	}
}