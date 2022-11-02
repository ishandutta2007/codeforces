#include<cstdio>

#define mo 1000000007

using namespace std;

int a,b,ans,rev;

int Pow(int x,int m)
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

int main()
{
	rev=Pow(2,mo-2);
	scanf("%d%d",&a,&b);
	for(int i=1;i<b;i++)(ans+=1ll*(1ll*b*i%mo+i+1ll*b*i%mo*a%mo+i)*a%mo*rev%mo)%=mo;
	printf("%d",ans);
}