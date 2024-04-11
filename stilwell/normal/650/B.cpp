#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int n,ans,i,j,k,l,r,mid,aim,p;
int sum[1000005];
char s[1000005];
long long tmp,a,b,T;

int calc(int a,int b)
{
	--a;b=n-b+1;
	if(a>b)swap(a,b);
	return a+a+b;
}

int main()
{
	scanf("%d%I64d%I64d%I64d",&n,&a,&b,&T);
	scanf("%s",s+1);
	for(i=1;i<=n;++i)sum[i]=sum[i-1]+(s[i]=='w');
	mid=2;
	for(i=1;i<=n;++i)
	{
		tmp=(i-1)*a+sum[i]*b+i;
		if(tmp<=T)
		{
			if(i>ans)ans=i;
			if(i+1>mid)mid=i+1;
			for(;mid<=n;++mid)
			{
				tmp=calc(i,mid)*a+(sum[i]+sum[n]-sum[mid-1])*b+(i+n-mid+1);
				if(tmp<=T)break;
			}
			k=i+n-mid+1;
			if(k>ans)ans=k;
		}
	}
	if(ans>n)ans=n;
	printf("%d\n",ans);
}