#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long a[105],l,r;
int i,j,ans;

long long calc(long long x)
{
	if(x<10)return x+1;
	if(x<100)return x/10+10-(x/10>x%10);
	long long tmp=x,y=1,ans=0;
	int i;
	for(i=1;tmp>=10;++i)
	{
		ans+=a[i];
		tmp/=10;
		y*=10;
	}
	y=x%y/10+1;
	ans+=a[i]/9*(tmp-1);
	if(tmp>x%10)--y;
	ans+=y;
	return ans;
}

int main()
{
	a[1]=10;a[2]=9;
	for(i=3;i<=18;++i)a[i]=a[i-1]*10;
	scanf("%I64d%I64d",&l,&r);
	printf("%I64d\n",calc(r)-calc(l-1));
}