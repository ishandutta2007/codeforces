#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int T,x1,x2,y1,y2,i,j,k;
long long ans1,ans2,ans3,p;

long long mult(long long a,long long b)
{
	a%=p;b%=p;if(b<0)b+=p;
	long long ans=0;
	for(;b;b>>=16)
	{
		ans=(ans+a*(b&65535))%p;
		a=(a<<16)%p;
	}
	return ans;
}

long long sum1(long long n)
{
	long long n0=n+1;
	if(n%2==0)n/=2;else n0/=2;
	return mult(n,n0);
}

long long sum2(long long n)
{
	long long n1=n+1,n2=n+n+1;
	if(n%2==0)n/=2;else if(n1%2==0)n1/=2;else n2/=2;
	if(n%3==0)n/=3;else if(n1%3==0)n1/=3;else n2/=3;
	return mult(mult(n,n1),n2);
}

long long calc(long long x,long long y)
{
	if(!x||!y)return 0;
	if(x==y)return sum1(x*x);
	if(x>y) return (sum1(y*y)+mult(y,sum2(x)-sum2(y))+p-mult(sum1(y-1),x-y))%p;
	else return (sum1(x*x)+mult(x,sum2(y-1)-sum2(x-1))+mult(sum1(x),y-x))%p;
}

void cal(long long &ans)
{
	ans=calc(x2,y2)-calc(x2,y1-1)-calc(x1-1,y2)+calc(x1-1,y1-1);
	ans=(ans%p+p)%p;
}

int main()
{
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		p=10000000000ll;cal(ans1);
		p=10000000001ll;cal(ans2);
		if(ans1!=ans2)printf("...%010I64d\n",ans1%10000000000ll);
		else printf("%I64d\n",ans1);
	}
}