#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,nmid,d,b,i,j,k,ll,rr,mid,ans;
int ls[100005],rs[100005];
int a[100005],aa[100005];

bool check(int now)
{
	int i,j,k,w,ll=now+1,rr=n-now;
	for(i=1;i<=n;++i)a[i]=aa[i];
	for(i=ll,k=1;i<=nmid;++i)
	{
		for(;k<ls[i];++k);
		for(w=b;k<=rs[i];++k)
		{
			if(a[k]>=w)
			{
				a[k]-=w;
				w=0;
				break;
			}
			w-=a[k];a[k]=0;
		}
		if(w)return false;
	}
	for(i=rr,k=n;i>nmid;--i)
	{
		for(;k>rs[i];--k);
		for(w=b;k>=ls[i];--k)
		{
			if(a[k]>=w)
			{
				a[k]-=w;
				w=0;
				break;
			}
			w-=a[k];a[k]=0;
		}
		if(w)return false;
	}
	return true;
}

int main()
{
	scanf("%d%d%d",&n,&d,&b);
	for(i=1;i<=n;++i)scanf("%d",&a[i]),aa[i]=a[i];
	for(i=1;i<=n;++i)
	{
		k=min((long long)d*min(i,n-i+1),(long long)n);
		ls[i]=max(1,i-k);
		rs[i]=min(n,i+k);
	}
	nmid=n/2+n%2;ans=n;
	for(ll=0,rr=n/2+n%2;ll<=rr;)
	{
		mid=ll+rr>>1;
		if(check(mid))ans=mid,rr=mid-1;
		else ll=mid+1;
	}
	printf("%d\n",ans);
}