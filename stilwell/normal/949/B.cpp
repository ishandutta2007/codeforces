#include <stdio.h>
#include <stdlib.h>
using namespace std;

int m,q,i,j,k;
long long n,l[10005],r[10005],ll,rr,x;

void work(long long ll,long long rr)
{
	++m;l[m]=ll;r[m]=rr;
	if(ll<=1)
	{
		l[m]=1;
		return;
	}
	long long w=rr-ll+1;
	work(ll-2*w,ll-1);
}

void query(long long x)
{
	for(i=m;i>=1;--i)
	if(x>=l[i]&&x<=r[i])
	{
		if(x&1)
		{
			printf("%I64d\n",x/2+1);
			return;
		}
		long long w=(r[i]-x)/2+1;
		x=r[i-1]-w+1;
	}
}

int main()
{
	scanf("%I64d%d",&n,&q);
	work(2*n-1,2*n-1);
	for(;q;--q)
	{
		scanf("%I64d",&x);
		query(x);
	}
}