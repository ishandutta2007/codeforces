#include <cstdio>
using namespace std;
long long n,m,k,p,a,b;
long long gcd(long long a,long long b)
{
	if (a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	a=n;
	b=m;
	p=gcd(n,k);
	n/=p;
	k/=p;
	p=gcd(m,k);
	m/=p;
	k/=p;
	if (k>2)
	{
		printf("NO\n");
		return 0;
	}
	if (k==1)
		if (2ll*n<=a)
			n*=2ll;
		else
			if (2ll*m<=b)
				m*=2ll;
			else
			{
				printf("NO\n");
				return 0;
			}
	printf("YES\n");
	printf("0 0\n");
	printf("%lld 0\n",n);
	printf("0 %lld\n",m);
	return 0;
}