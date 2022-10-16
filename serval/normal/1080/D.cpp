#include <cstdio>
using namespace std;
const long long inf=0x7fffffffffffffff;
int t;
long long n,k,z,q,x,y;
long long l,r,mid;
long long cal(long long q)
{
	long long ret=0;
	long long a=1;
	q++;
	while (q--)
	{
		ret+=a;
		if (q)
		{
			if (inf/a<=4)
				return inf;
			a=a*4;
		}
	}
	return ret;
}
bool check(long long p)
{
	if (n-p<=0)
		return 0;
	z=0;
	q=0;
	x=2;
	while (z<n-p)
	{
		q+=x-1;
		x<<=1;
		if (q>k)
			return 0;
		z++;
	}
	z=0;
	x=1;
	while (z<n-p)
	{
		if (n-z-2<0)
			break;
		if (cal(n-z-2)>=inf)
			return 1;
		y=cal(n-z-2);
		if (x>=(k-q+y-1)/y)
			return 1;
		q+=x*y;
		if (q>=k)
			return 1;
		x<<=1;
		x+=3;
		z++;
	}
	if (q>=k)
		return 1;
	return 0;
}
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld%lld",&n,&k);
		for (r=0;r<=10000;r++)
		{
			if (n-r<0)
				r=10000;
			else
				if (check(n-r))
				{
					printf("YES %lld\n",n-r);
					break;
				}
		}
		if (r>10000)
			printf("NO\n");
	}
	return 0;
}