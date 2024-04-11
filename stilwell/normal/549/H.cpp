#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int i,a,b,c,d;
long double la,ra,lb,rb,lc,rc,ld,rd,l,r,mid,l1,l2,r1,r2;

bool check(long double x)
{
	la=a-(-x);ra=a-x;
	lb=b-(-x);rb=b-x;
	lc=c-(-x);rc=c-x;
	ld=d-(-x);rd=d-x;
	l1=min(min(la*ld,la*rd),min(ra*ld,ra*rd));
	r1=max(max(la*ld,la*rd),max(ra*ld,ra*rd));
	l2=min(min(lb*lc,lb*rc),min(rb*lc,rb*rc));
	r2=max(max(lb*lc,lb*rc),max(rb*lc,rb*rc));
	if(l1>l2)swap(l1,l2),swap(r1,r2);
	if(l2<=r1)return true;
	else return false;
}

int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	l=0;r=1000000000;
	for(i=1;i<=200;++i)
	{
		mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	printf("%.10lf\n",(double)mid);
}