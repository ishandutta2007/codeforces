#include <stdio.h>
#include <stdlib.h>
using namespace std;

long long a,b,ans;

void gcd(long long a,long long b)
{
	if(!b)return;
	ans+=a/b;
	gcd(b,a%b);
}

int main()
{
	scanf("%I64d%I64d",&a,&b);
	gcd(a,b);
	printf("%I64d\n",ans);
}