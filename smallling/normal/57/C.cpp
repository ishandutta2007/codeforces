#include<cstdio>

#define mo 1000000007

using namespace std;

int ans,n,now,a,b;

int pow(int x,int m)
{
	int nowans=1;
	while(m)
	{
		if(m&1)nowans=1ll*nowans*x%mo;
		x=1ll*x*x%mo;
		m>>=1;
	}
	return nowans;
}

void C(int a,int b)
{
	ans=1;
	for(int i=b+1;i<=a;i++)
		ans=(1ll*ans*i)%mo;
	now=1;
	for(int i=1;i<=a-b;i++)
		now=(1ll*now*i)%mo;
	ans=(1ll*ans*pow(now,mo-2))%mo;
}

int main()
{
	scanf("%d",&n);
	a=n+n-1;
	b=n-1;
	C(a,b);
	printf("%d\n",((ans+ans)%mo-n+mo)%mo);
}