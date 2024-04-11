#include<cstdio>

#define mo 1000003

using namespace std;

int n,nowans,x;

int pow(int m)
{
	nowans=1;
	x=3;
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
	scanf("%d",&n);
	if(n==0)return puts("1");
	printf("%d",pow(n-1));
}