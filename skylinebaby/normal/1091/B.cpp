#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b;
	int n;
	scanf("%d",&n);
	a = 0, b= 0;
	for(int i = 0;i<2*n;i++)
	{
		long long x,y;
		scanf("%lld %lld",&x,&y);
		a += x;
		b += y;
	}
	printf("%lld %lld\n",a/n,b/n);
	return 0;
}