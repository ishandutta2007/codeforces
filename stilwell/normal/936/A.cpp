#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long k,w,d,t,ans;

int main()
{
	scanf("%lld%lld%lld",&k,&d,&t);
	k*=2;d*=2;t*=2;
	w=k/d*d;if(w<k)w+=d;
	for(;t;)
	if(t>=w)
	{
		ans+=t/w*w;
		t-=t/w*(k+(w-k)/2);
	}
	else
	{
		if(t<=k)ans+=t,t=0;
		else
		{
			if(k+(t-k)*2<=w)ans+=k+(t-k)*2,t=0;
			else
			{
				ans+=w;
				t-=k+(w-k)/2;
			}
		}
	}
	printf("%lld",ans/2);
	if(ans%2)printf(".5");
	printf("\n");
	
}