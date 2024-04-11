#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;
int n,m;
int main()
{
	scanf("%d",&n);
	long long p,q,b,g;
	while(n--)
	{
		scanf("%lld%lld%lld",&p,&q,&b);
		g=__gcd(p,q);
		p/=g,q/=g;
		g=__gcd(q,b);
		while(g!=1)
		{
			q/=g;
			if(q%g!=0)g=__gcd(q,g);
		}
		if(q!=1)printf("Infinite\n");
		else printf("Finite\n");
	}
	return 0;
}