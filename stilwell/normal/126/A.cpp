#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

long long t1,t2,x1,x2,t0,ans1,ans2,y1,y2;

int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&t1,&t2,&x1,&x2,&t0);
	if(t1==t2)
	{
		printf("%I64d %I64d\n",x1,x2);
		return 0;
	}
	if(t0==t2)
	{
		printf("0 %I64d\n",x2);
		return 0;
	}
	ans1=0;ans2=1;y2=0;
	for(y1=1;y1<=x1;++y1)
	{
		while(((t1*y1+t2*y2)<t0*(y1+y2))&&y2<=x2)++y2;
		if(y2>x2)break;
		if((t1*y1+t2*y2)*(ans1+ans2)<=(t1*ans1+t2*ans2)*(y1+y2))
		{
			ans1=y1;
			ans2=y2;
		}
	}
	if(t2*(ans1+ans2)<(t1*ans1+t2*ans2))
	ans1=0,ans2=x2;
	if(t2*(ans1+ans2)==(t1*ans1+t2*ans2))
	if(x2>ans1+ans2)
	ans1=0,ans2=x2;
	printf("%I64d %I64d\n",ans1,ans2);
}