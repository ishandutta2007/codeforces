#include <cstdio>
#include <cmath>
using namespace std;
const int N=100005;
int n,i,j;
int x[N],y[N];
bool neg;
double l,r,mid;
long double b,c,sq;
long double curl,curr;
bool check(long double r)
{
	if (neg)
		r=-r;
	curl=-1e18;
	curr=1e18;
	for (i=1;i<=n;i++)
	{
		b=-1.0*x[i];
		c=(r+r-1.0*y[i])*(1.0*y[i])-1.0*x[i]*x[i];
		if (b*b+c<0)
			return 0;
		sq=sqrt(b*b+c);
		if (b-sq>curl)
			curl=b-sq;
		if (b+sq<curr)
			curr=b+sq;
	}
	return curl<=curr;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (i=1;i<=n;i++)
		if ((y[i]<0)^(y[1]<0))
		{
			printf("-1\n");
			return 0;
		}
	l=0;
	r=1e18;
	neg=y[1]<0;
	for (j=1;j<=100;j++)
	{
		mid=(l+r)/2;
		if (check(mid))
			r=mid;
		else
			l=mid;
	}
	printf("%.10lf\n",mid);
	return 0;
}