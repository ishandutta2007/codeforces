#include <cstdio>
#include <algorithm>
using namespace std;
int t;
long long n,m;
long long a,b,c,d;
long long i,j,k,l;
long long p,q,r,s;
long long x,y;
long long bl,wh;
int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%lld %lld",&m,&n);
		bl=n*m/2;
		wh=n*m-bl;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		scanf("%lld%lld%lld%lld",&i,&j,&k,&l);
		x=(c-a+1)*(d-b+1)/2;
		y=(c-a+1)*(d-b+1)-x;
		if ((a&1)^(b&1))
		{
			bl-=y;
			wh+=y;
		}
		else
		{
			bl-=x;
			wh+=x;
		}
		x=(k-i+1)*(l-j+1)/2;
		y=(k-i+1)*(l-j+1)-x;
		if ((i&1)^(j&1))
		{
			wh-=x;
			bl+=x;
		}
		else
		{
			wh-=y;
			bl+=y;
		}
		p=max(a,i);
		q=max(b,j);
		r=min(c,k);
		s=min(d,l);
		if (r>=p&&s>=q)
		{
			x=(r-p+1)*(s-q+1)/2;
			y=(r-p+1)*(s-q+1)-x;
			if ((p&1)^(q&1))
			{
				wh-=y;
				bl+=y;
			}
			else
			{
				wh-=x;
				bl+=x;
			}
		}
		printf("%lld %lld\n",wh,bl);
	}
	return 0;
}