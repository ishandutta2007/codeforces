#include <cstdio>
#include <cmath>
using namespace std;
int t;
long long x,a,b,c,p,q;
bool fd;
const long long mx=1000000000;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%I64d",&x);
		if (x==0)
		{
			printf("1 1\n");
			continue;
		}
		fd=0;
		for (a=1;a*a<=x;a++)
			if (x%a==0)
			{
				b=x/a;
				if ((a+b)&1)
					continue;
				c=(a+b)>>1;
				p=b-c;
				if (p<0)
					p=-p;
				q=c/(p+1);
				while (c/q>p)
					q++;
				if (q>c)
					continue;
				if (c/q==p&&c<=mx&&q<=mx)
				{
					printf("%I64d %I64d\n",c,q);
					fd=1;
					break;
				}
			}
		if (!fd)
			printf("-1\n");
	}
	return 0;
}