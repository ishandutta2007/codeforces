#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define p 1000000007
using namespace std;

int n,n1,n2,n3,n4,m,m0,i,j,k;
char s[100005];

long long Power(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b%2)ans=ans*a%p;
		a=a*a%p;
		b/=2;
	}
	return ans;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;++i)
	{
		if(s[i]=='A')++n1;
		if(s[i]=='C')++n2;
		if(s[i]=='G')++n3;
		if(s[i]=='T')++n4;
	}
	m=m0=0;
	if(n1==m)++m0;if(n1>m)m=n1,m0=1;
	if(n2==m)++m0;if(n2>m)m=n2,m0=1;
	if(n3==m)++m0;if(n3>m)m=n3,m0=1;
	if(n4==m)++m0;if(n4>m)m=n4,m0=1;
	printf("%I64d\n",Power(m0,n));
}