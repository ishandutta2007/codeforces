#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,l,r,p,i,j,k,ll,rr,num,q,flag;
long long ans,tmp;
vector<int> t[100005];

int calc(int q,int r)
{
	r=min(r,m);
	long long tmp=r/q;
	long long ans=tmp*(m+1)-(1+tmp)*tmp/2*q;
	return ans%p;
}

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&l,&r,&p);
	for(i=2;i<=n;++i)
	if(!t[i].size())
	for(j=i;j<=n;j+=i)
	t[j].push_back(i);
	ans=0;
	if(l<=1)ans+=(long long)(n+1)*m%p+(long long)n*(m+1)%p;
	ans%=p;
	for(i=1;i<=n;++i)
	{
		if(i>=r)break;
		ll=(int)sqrt(max((long long)l*l-(long long)i*i-1,0ll));
		rr=(int)sqrt((long long)r*r-(long long)i*i);
		if(ll==rr)continue;
		num=t[i].size();
		tmp=0;
		for(j=(1<<num)-1;j>=0;--j)
		{
			q=1;flag=1;
			for(k=0;k<num;++k)
			if(j&(1<<k))
			{
				q*=t[i][k];
				flag=-flag;
			}
			tmp=(tmp+(calc(q,rr)-calc(q,ll))*flag+p)%p;
		}
		tmp*=2;
		ans=(ans+tmp*(n-i+1))%p;
	}
	printf("%I64d\n",ans);
}