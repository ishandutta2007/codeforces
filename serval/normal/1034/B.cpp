#include <cstdio>
using namespace std;
long long n,m,i,j;
int main()
{
	scanf("%lld%lld",&n,&m);
	if (m<n)
		n^=m^=n^=m;
	if (n==1)
	{
		if ((m-1)%6<3)
		{
			printf("%lld\n",m/6*6);
			return 0;
		}
		if ((m-1)%6==3)
		{
			printf("%lld\n",m/6*6+2);
			return 0;
		}
		if ((m-1)%6==4)
		{
			printf("%lld\n",m/6*6+4);
			return 0;
		}
		if ((m-1)%6==5)
		{
			printf("%lld\n",m/6*6);
			return 0;
		}
	}
	if (n==2&&m<=2)
	{
		printf("0\n");
		return 0;
	}
	if (n==2&&(m==3||m==7))
	{
		printf("%lld\n",n*m-2);
		return 0;
	}
	printf("%lld\n",(n*m)&(~1ll));
	return 0;
}