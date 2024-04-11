#include<stdio.h>
using namespace std;
typedef long long LL;
LL a,b,x,y,n,m;LL x1,y1,x2,y2;
LL gcd(LL a,LL b){if(a==0||b==0)return a^b;return gcd(b,a%b);}
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&n,&m,&x,&y,&a,&b);
	long k=gcd(a,b);a/=k;b/=k;
	long s=n/a;
	if(m/b<s)s=m/b;
	a*=s;b*=s;
	if(x<a/2)
	{
		x1=0;x2=a;
	}
	else
	if(a/2+x>n)
	{
		x1=n-a;x2=n;
	}
	else
	{
		if(x-(a+1)/2>=0)x1=x-(a+1)/2;
		else x1=x-a/2;
		x2=x1+a;
	}
	if(y<b/2)
	{
		y1=0;y2=b;
	}
	else
	if(b/2+y>m)
	{
		y1=m-b;y2=m;
	}
	else
	{
		if(y-(b+1)/2>=0)y1=y-(b+1)/2;
		else y1=y-a/2;
		y2=y1+b;
	}
	printf("%I64d %I64d %I64d %I64d\n",x1,y1,x2,y2);
	return 0;
}