#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long int ll;

ll n,t,k;

int main()
{
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		k=1;
		while (k<=n) k*=2;
		k=(k-1)*2;
		printf("%I64d\n",n*(n+1)/2-k);
	}
	return 0;
}