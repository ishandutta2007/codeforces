#include<stdio.h>
using namespace std;
typedef long long LL;
LL a[110000],n,m;
LL now=0;
int main()
{
	scanf("%I64d%I64d",&n,&m);
	for(LL i=1;i<=m;i++)scanf("%I64d",&a[i]);
	now=1;LL time=0;
	for(LL i=1;i<=m;i++)
	{
		if(a[i]>now)time+=a[i]-now;
		else if(a[i]<now){time+=n-now;time+=a[i];}
		now=a[i];
	}
	printf("%I64d",time);
	//for(;;);
	return 0;
}